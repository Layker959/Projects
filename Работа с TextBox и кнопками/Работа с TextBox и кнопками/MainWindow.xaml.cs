using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection.Emit;
using System.Runtime.Remoting.Messaging;
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

namespace Работа_с_TextBox_и_кнопками
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
            double v1 = 1;
            double v2 = 2;
            double v3 = 3;
            if (Vvod1.Text == "" || Vvod2.Text == "" || Vvod3.Text == "")
            {
                MessageBox.Show("Ошибка: Не все числа введены");
            }
            else
            {
                try
                {
                    v1 = Convert.ToDouble(Vvod1.Text);
                }
                catch
                {
                    MessageBox.Show("Ошибка: первое число введено неверно");
                }
                try
                {
                    v2 = Convert.ToDouble(Vvod2.Text);
                }
                catch
                {
                    MessageBox.Show("Ошибка: второе число введено неверно");
                }
                try
                {
                    v3 = Convert.ToDouble(Vvod3.Text);
                }
                catch
                {
                    MessageBox.Show("Ошибка: третье число введено неверно");
                }
                if (v1 == 0 || v2 == 0)
                {
                    MessageBox.Show("Ошибка: на 0 делить нельзя");
                }
                else
                {
                    double addition = v1 + v2 + v3;       // +
                    double subtraction = v1 - v2 - v3;    // -
                    double multiplication = v1 * v2 * v3; // *
                    double division = v1 / v2 / v3;       // /
                    MessageBox.Show($"Сумма: {addition}\nРазность: {subtraction}\nПроизведение: {multiplication}\nЧастное: {division}");
                }
            }
        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            Close();
        }

        private void colorComboBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            switch (colorComboBox.Text)
            {
                case "Чёрный":
                    title.Background = Brushes.Black;
                    break;
                case "Красный":
                    title.Background = Brushes.Red;
                    break;
                case "Синий":
                    title.Background = Brushes.Blue;
                    break;
                case "Зелёный":
                    title.Background = Brushes.Green;
                    break;

            }
        }
    }
}
