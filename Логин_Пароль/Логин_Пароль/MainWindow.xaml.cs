using System;
using System.Collections.Generic;
using System.Diagnostics.Eventing.Reader;
using System.IO;
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

namespace Логин_Пароль
{
    /// <summary>
    /// Логика взаимодействия для MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            string path = @"C:\LogsC#\login_password.txt";
            FileInfo fileInf = new FileInfo(path);
            using (StreamReader sr = new StreamReader(path))
            {
                sr.ReadToEnd();
            }
            if (fileInf.Exists)
            {

            }
            else
            {
                MessageBox.Show("Данные неверны");
                Directory.GetCurrentDirectory();
                string path1 = @"C:\LogsC#\lastEnter.txt";
                File.Exists(path1);

                DateTime dt = DateTime.Now;
                TimeSpan ts = dt - DateTime.Now;
                string readPath = @"C:\LogsC#\lastEnter.txt";
                string writePath = @"C:\LogsC#\lastEnter.txt";
                string text = $"{dt}";
                using (StreamReader sr = new StreamReader(readPath, System.Text.Encoding.Default))
                {
                    text = sr.ReadToEnd();
                }
                using (StreamWriter sw = new StreamWriter(writePath, false, System.Text.Encoding.Default))
                {
                    sw.WriteLine(text);
                }
                using (StreamWriter sw = new StreamWriter(writePath, true, System.Text.Encoding.Default))
                {
                    sw.WriteLine("Неудачная попытка входа");
                    sw.Write(dt);
                }
            }
        }
    }
}
