using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Remoting.Contexts;
using System.Windows;

namespace Задание_13
{
    public partial class MainWindow : Window
    {
        private string connectionString = "Server=DESKTOP-DP6O776;Database=Продукты_Заказы;Integrated Security=true;";
        private SupplierOrdersContext _context;

        public MainWindow()
        {
            InitializeComponent();
            _context = new SupplierOrdersContext();
            _context.Database.EnsureCreated(); 
            LoadSuppliers();
        }

        private void LoadSuppliers()
        {
            SupplierComboBox.ItemsSource = _context.Suppliers.ToList();
        }

        private void AddOrderButton_Click(object sender, RoutedEventArgs e)
        {
            if (SupplierComboBox.SelectedItem is Supplier selectedSupplier)
            {
                var order = new Order { OrderDate = DateTime.Now, SupplierID = selectedSupplier.SupplierID };
                _context.Orders.Add(order);
                _context.SaveChanges();
                LoadOrders(selectedSupplier.SupplierID);
            }
        }

        private void DeleteOrderButton_Click(object sender, RoutedEventArgs e)
        {
            if (OrdersDataGrid.SelectedItem is Order selectedOrder)
            {
                _context.Orders.Remove(selectedOrder);
                _context.SaveChanges();
                LoadOrders(selectedOrder.SupplierID);
            }
        }

        private void SupplierComboBox_SelectionChanged(object sender, System.Windows.Controls.SelectionChangedEventArgs e)
        {
            if (SupplierComboBox.SelectedItem is Supplier selectedSupplier)
            {
                LoadOrders(selectedSupplier.SupplierID);
            }
        }

        private void LoadOrders(int supplierID)
        {
            OrdersDataGrid.ItemsSource = _context.Orders.Where(o => o.SupplierID == supplierID).ToList();
        }
    }

    public class SupplierOrdersContext : DbContext
    {
        public DbSet<Supplier> Suppliers { get; set; }
        public DbSet<Order> Orders { get; set; }

        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            optionsBuilder.UseSqlServer("Server=(localdb)\\mssqllocaldb;Database=SupplierOrdersDB;Trusted_Connection=True;");
        }
    }

    public class Supplier
    {
        public int SupplierID { get; set; }
        public string SupplierName { get; set; }
    }

    public class Order
    {
        public int OrderID { get; set; }
        public DateTime OrderDate { get; set; }
        public int SupplierID { get; set; }
    }
}