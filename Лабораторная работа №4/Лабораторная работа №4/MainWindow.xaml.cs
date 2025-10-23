using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using WizardD;

namespace Лабораторная_работа__4
{
    /// <summary>
    /// Логика взаимодействия для MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        Random r = new Random();
        public MainWindow()
        {
            InitializeComponent();
        }
        private void Entr_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                ComboBoxItem selectedItem = (ComboBoxItem)spisok.SelectedItem;
                if (selectedItem == null)
                {
                    throw new Exception("Выберите элемент из списка!");
                }

                string selectedClass = selectedItem.Content.ToString();
                Type wizardType = WizardType(selectedClass);

                WizardD.Wizard wizard = (WizardD.Wizard)Activator.CreateInstance(wizardType);

                Text2.Text = wizard.method();
            }
            catch (Exception ex)
            {
                Text2.Text = $"Ошибка: {ex.Message}";
            }
        }

        private Type WizardType(string selectedClass)
        {
            switch (selectedClass)
            {
                case "Маг":
                    return typeof(WizardD.Wizard);
                case "Некромант":
                    return typeof(WizardD.Necromancer);
                case "Друид":
                    return typeof(WizardD.Druid);
                default:
                    throw new Exception($"Неизвестный класс: {selectedClass}");
            }
        }
    }
}
