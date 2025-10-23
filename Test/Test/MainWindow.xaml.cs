using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows;
using System.Windows.Controls;
using System.Timers;
using System.Reflection.Emit;
using System.Windows.Media;
namespace LeanDevelopmentTest
{
    public partial class MainWindow : Window
    {
        private List<Question> questions;
        private int currentQuestionIndex = 0;
        private int score = 0;
        private static Timer TimerEnd;
        private int BaseMinutes = 0;
        private int BaseSeconds = 30;
        private int minutes;
        private int seconds;
        private string TimerTime;
        // Настройки порогов оценок
        private int grade2Threshold = 5; // Оценка 2 — менее этого значения
        private int grade3Threshold = 5; // Оценка 3 — от grade3Threshold до grade4Threshold
        private int grade4Threshold = 7; // Оценка 4 — от grade4Threshold до grade5Threshold
        private int grade5Threshold = 9; // Оценка 5 — от grade5Threshold
        private bool isTimeEnded;

        public MainWindow()
        {
            InitializeComponent();
            LoadQuestions();
            UpdateTimer();

            Timer.Content = TimerTime;
            SetTimer();
            TimerEnd.Start();

        }
        private void UpdateTimer()
        {
            minutes = BaseMinutes;
            seconds = BaseSeconds;
            if (seconds <= 9)
            {
                TimerTime = minutes + ":0" + seconds;
            }
            else { TimerTime = minutes + ":" + seconds; }
            Timer.Content = TimerTime;
        }
        private void SetTimer()
        {
            TimerEnd = new Timer(1000);
            TimerEnd.Elapsed += OnTimedEvent;
            TimerEnd.AutoReset = true;
            TimerEnd.Enabled = true;
        }

        private void OnTimedEvent(object sender, EventArgs e)
        {
            
            if (seconds <= 0 && minutes != 0)
            {
                minutes -= 1;
                seconds = 59;
                if (seconds <= 9)
                {
                    TimerTime = minutes + ":0" + seconds;
                }
                else { TimerTime = minutes + ":" + seconds; }
                
            }
            else if (seconds <= 0 && minutes <= 0)
            {
                TimerTime = "Время на вопрос истекло";
                isTimeEnded = true;
                TimerEnd.Stop();
                
            }
            else if (seconds > 0) 
            { 
                seconds -= 1;
                if (seconds <= 9)
                {
                    TimerTime = minutes + ":0" + seconds;
                }
                else { TimerTime = minutes + ":" + seconds; }
            }
            Timer.Dispatcher.Invoke(new Action(() => {
                Timer.Content = TimerTime;
            }));
            if (isTimeEnded)
            {
                Answer1.Dispatcher.Invoke(new Action(() => {
                    Answer1.IsEnabled = false;
                }));
                Answer2.Dispatcher.Invoke(new Action(() => {
                    Answer2.IsEnabled = false;
                }));
                Answer3.Dispatcher.Invoke(new Action(() => {
                    Answer3.IsEnabled = false;
                }));
                Answer4.Dispatcher.Invoke(new Action(() => {
                    Answer4.IsEnabled = false;
                }));
          
            }




        }

        private void LoadQuestions()
        {
            questions = new List<Question>
            {
               new Question("Что такое бережливая разработка?",
            new List<string> { "Методология управления проектами", "Методология разработки ПО", "Методология тестирования ПО", "Методология документирования ПО" },
            1, 3),

        new Question("Какой из принципов бережливой разработки направлен на устранение потерь?",
            new List<string> { "Устранение потерь", "Усиление обучения", "Отсрочка принятия решений", "Доставка как можно быстрее" },
            0, 3),

        new Question("Что означает принцип 'Усиление обучения' в бережливой разработке?",
            new List<string> { "Постоянное обучение команды", "Использование новых технологий", "Проведение тренингов", "Все вышеперечисленное" },
            3, 3),

        new Question("Какой метод бережливой разработки помогает минимизировать потери?",
            new List<string> { "Scrum", "Канбан", "Waterfall", "Extreme Programming (XP)" },
            1, 3),

        new Question("Что является основной целью бережливой разработки программного обеспечения?",
            new List<string> { "Увеличение количества документации", "Максимизация прибыли компании", "Создание ценности для клиента с минимальными затратами", "Ускорение выпуска продукта без учета качества" },
            2, 3),

        new Question("Какой из перечисленных принципов НЕ относится к бережливой разработке?",
            new List<string> { "Устранение потерь", "Отсрочка принятия решений", "Постоянное улучшение", "Уважение к людям" },
            1, 3),

        new Question("Что такое \"муда\" (muda) в контексте бережливой разработки?",
            new List<string> { "Ценность для клиента", "Любые потери или бесполезные действия", "Быстрая доставка продукта", "Автоматизация процессов" },
            1, 3),

        new Question("Что означает принцип \"точно в срок\" (Just-in-Time) в бережливой разработке?",
            new List<string> { "Выполнение задач в последний момент", "Производство только того, что нужно, когда нужно и в нужном количестве", "Ускорение всех процессов без учета качества", "Отказ от планирования" },
            1, 3),

        new Question("Какой из перечисленных элементов НЕ является частью бережливой разработки?",
            new List<string> { "Постоянное улучшение (Kaizen)", "Минимизация отходов (муда)", "Жесткое следование первоначальному плану", "Вовлечение всей команды в процесс" },
            2, 3),

        new Question("Какой из перечисленных подходов лучше всего соответствует принципам бережливой разработки?",
            new List<string> { "Waterfall", "Agile", "Spiral", "V-Model" },
            1, 3)
            };
        }

        private void StartButton_Click(object sender, RoutedEventArgs e)
        {
            MainPanel.Visibility = Visibility.Collapsed;
            TestPanel.Visibility = Visibility.Visible;
            ShowQuestion();
        }

        private void SettingsButton_Click(object sender, RoutedEventArgs e)
        {
            MainPanel.Visibility = Visibility.Collapsed;
            SettingsPanel.Visibility = Visibility.Visible;

            // Создаем интерфейс для настройки баллов
            QuestionsStackPanel.Children.Clear();
            foreach (var question in questions)
            {
                var stackPanel = new StackPanel { Orientation = Orientation.Horizontal, Margin = new Thickness(0, 5, 0, 5) };
                var textBlock = new TextBlock { Text = question.Text, Width = 400, TextWrapping = TextWrapping.Wrap };
                var textBox = new TextBox { Text = question.Points.ToString(), Width = 50 };

                stackPanel.Children.Add(textBlock);
                stackPanel.Children.Add(textBox);

                QuestionsStackPanel.Children.Add(stackPanel);
            }
        }

        private void SaveSettings_Click(object sender, RoutedEventArgs e)
        {
            if (QuestionsStackPanel.Children.Count != questions.Count)
            {
                MessageBox.Show("Ошибка при сохранении настроек!", "Ошибка", MessageBoxButton.OK, MessageBoxImage.Error);
                return;
            }

            int totalPoints = 0; // Переменная для подсчета общего количества баллов

            for (int i = 0; i < questions.Count; i++)
            {
                var stackPanel = (StackPanel)QuestionsStackPanel.Children[i];
                var textBox = (TextBox)stackPanel.Children[1];

                if (int.TryParse(textBox.Text, out int points))
                {
                    questions[i].Points = points;
                    totalPoints += points; // Суммируем баллы
                }
                else
                {
                    MessageBox.Show($"Некорректное значение баллов для вопроса \"{questions[i].Text}\"!", "Ошибка", MessageBoxButton.OK, MessageBoxImage.Warning);
                    return;
                }
            }

            // Обновляем текст с общим количеством баллов
            TotalPointsTextBlock.Text = $"Общее количество баллов: {totalPoints}";

            MessageBox.Show("Настройки успешно сохранены!", "Успех", MessageBoxButton.OK, MessageBoxImage.Information);
        }

        private void BackToMain_Click(object sender, RoutedEventArgs e)
        {
            SettingsPanel.Visibility = Visibility.Collapsed;
            MainPanel.Visibility = Visibility.Visible;
        }

        private void ConfigureGradesButton_Click(object sender, RoutedEventArgs e)
        {
            MainPanel.Visibility = Visibility.Collapsed;
            GradesSettingsPanel.Visibility = Visibility.Visible;
        }

        private void SaveGradesSettings_Click(object sender, RoutedEventArgs e)
        {
            if (int.TryParse(Grade2ThresholdTextBox.Text, out grade2Threshold) &&
                int.TryParse(Grade3ThresholdTextBox.Text, out grade3Threshold) &&
                int.TryParse(Grade4ThresholdTextBox.Text, out grade4Threshold) &&
                int.TryParse(Grade5ThresholdTextBox.Text, out grade5Threshold) &&
                int.TryParse(Grade5StartThresholdTextBox.Text, out int tempGrade5Threshold))
            {
                // Проверяем логичность порогов
                if (grade2Threshold >= grade3Threshold || grade3Threshold >= grade4Threshold || grade4Threshold >= tempGrade5Threshold)
                {
                    MessageBox.Show("Пороги оценок должны быть установлены по возрастанию!", "Ошибка", MessageBoxButton.OK, MessageBoxImage.Warning);
                    return;
                }

                grade5Threshold = tempGrade5Threshold;
                MessageBox.Show("Настройки оценок успешно сохранены!", "Успех", MessageBoxButton.OK, MessageBoxImage.Information);
            }
            else
            {
                MessageBox.Show("Введите корректные числовые значения для порогов оценок!", "Ошибка", MessageBoxButton.OK, MessageBoxImage.Warning);
            }
        }

        private void BackToMainFromGrades_Click(object sender, RoutedEventArgs e)
        {
            GradesSettingsPanel.Visibility = Visibility.Collapsed;
            MainPanel.Visibility = Visibility.Visible;
        }

        private void FinishButton_Click(object sender, RoutedEventArgs e)
        {
            // Проверяем, выбран ли ответ на последний вопрос
            if (!(Answer1.IsChecked == true || Answer2.IsChecked == true || Answer3.IsChecked == true || Answer4.IsChecked == true))
            {
                MessageBox.Show("Пожалуйста, выберите один из вариантов ответа!", "Ошибка", MessageBoxButton.OK, MessageBoxImage.Warning);
                return;
            }

            // Проверяем ответ на последний вопрос
            CheckAnswer();

            // Завершаем тест
            int maxScore = questions.Sum(q => q.Points);
            double percentage = (double)score / maxScore * 100;
            int finalGrade = CalculateFinalGrade(score);

            ResultText.Text = $"Тест завершен!\n" +
                              $"Ваш результат: {score} из {maxScore}\n" +
                              $"Итоговая оценка: {finalGrade}";

            // Отключаем все кнопки
            NextButton.IsEnabled = false;
            BackButton.IsEnabled = false;
            FinishButton.Visibility = Visibility.Collapsed;

            // Очищаем таймер
            TimerEnd.Stop();
        }

        private void ResetRadioButtons()
        {
            Answer1.IsChecked = false;
            Answer2.IsChecked = false;
            Answer3.IsChecked = false;
            Answer4.IsChecked = false;

            Answer1.IsEnabled = true;
            Answer2.IsEnabled = true;
            Answer3.IsEnabled = true;
            Answer4.IsEnabled = true;

            // Остановка и перезапуск таймера
            TimerEnd.Stop();
            UpdateTimer();
            SetTimer();
            TimerEnd.Start();
        }
        private void ShowQuestion()
        {
            if (currentQuestionIndex < questions.Count)
            {
                var question = questions[currentQuestionIndex];

                // Отображаем текст вопроса и варианты ответов
                QuestionText.Text = question.Text;
                Answer1.Content = question.Answers[0];
                Answer2.Content = question.Answers[1];
                Answer3.Content = question.Answers[2];
                Answer4.Content = question.Answers[3];

                // Сбрасываем состояние радиокнопок только для НЕ отвеченных вопросов
                if (!question.isAnswered)
                {
                    ResetRadioButtons();
                }

                // Восстанавливаем ранее выбранный ответ, если вопрос уже был отвечен
                if (question.isAnswered)
                {
                    switch (question.Checked)
                    {
                        case 0: Answer1.IsChecked = true; break;
                        case 1: Answer2.IsChecked = true; break;
                        case 2: Answer3.IsChecked = true; break;
                        case 3: Answer4.IsChecked = true; break;
                        default: break;
                    }
                }
            }
            else
            {
                // Тест завершен
                int maxScore = questions.Sum(q => q.Points);
                double percentage = (double)score / maxScore * 100;
                int finalGrade = CalculateFinalGrade(score);

                ResultText.Text = $"Тест завершен!\n" +
                                  $"Ваш результат: {score} из {maxScore}\n" +
                                  $"Итоговая оценка: {finalGrade}";

                // Отключаем кнопки навигации
                NextButton.IsEnabled = false;
                BackButton.IsEnabled = false;

                // Скрываем таймер и останавливаем его
                Timer.Visibility = Visibility.Collapsed;
                TimerEnd.Stop();
            }
        }

        

        private int CalculateFinalGrade(int totalScore)
        {
            if (totalScore < grade2Threshold)
                return 2;
            else if (totalScore >= grade3Threshold && totalScore < grade4Threshold)
                return 3;
            else if (totalScore >= grade4Threshold && totalScore < grade5Threshold)
                return 4;
            else
                return 5;
        }

        private void NextButton_Click(object sender, RoutedEventArgs e)
        {
            if (!(Answer1.IsChecked == true || Answer2.IsChecked == true || Answer3.IsChecked == true || Answer4.IsChecked == true))
            {
                MessageBox.Show("Пожалуйста, выберите один из вариантов ответа!", "Ошибка", MessageBoxButton.OK, MessageBoxImage.Warning);
                return;
            }

            CheckAnswer();
            if (currentQuestionIndex < questions.Count - 1)
            {
                currentQuestionIndex++;
                ShowQuestion();
            }
            else
            {
                MessageBox.Show("Это последний вопрос!", "Информация", MessageBoxButton.OK, MessageBoxImage.Information);
            }
        }
        private void BackButton_Click(object sender, RoutedEventArgs e)
        {
            if (currentQuestionIndex > 0)
            {
                currentQuestionIndex--;
                ShowQuestion();
            }
            else
            {
                MessageBox.Show("Это первый вопрос!", "Информация", MessageBoxButton.OK, MessageBoxImage.Information);
            }
        }

        private void CheckAnswer()
        {
            var question = questions[currentQuestionIndex];

            // Проверяем, какой RadioButton выбран и соответствует ли он правильному ответу
            if ((Answer1.IsChecked == true && question.CorrectAnswerIndex == 0) ||
                (Answer2.IsChecked == true && question.CorrectAnswerIndex == 1) ||
                (Answer3.IsChecked == true && question.CorrectAnswerIndex == 2) ||
                (Answer4.IsChecked == true && question.CorrectAnswerIndex == 3))
            {
                // Сохраняем индекс выбранного ответа
                if (Answer1.IsChecked == true) { question.Checked = 0; }
                else if (Answer2.IsChecked == true) { question.Checked = 1; }
                else if (Answer3.IsChecked == true) { question.Checked = 2; }
                else if (Answer4.IsChecked == true) { question.Checked = 3; }

                // Сохраняем время, оставшееся на вопрос
                question.Minutes = minutes;
                question.Seconds = seconds;

                // Если вопрос еще не был отвечен, добавляем баллы
                if (!question.isAnswered)
                {
                    score += question.Points;
                    question.isAnswered = true;
                }
            }
        }

    }

    public class Question
    {
        public string Text { get; set; }
        public List<string> Answers { get; set; }
        public int CorrectAnswerIndex { get; set; }
        public int Points { get; set; }
        public bool isAnswered { get; set; }
        public int Minutes { get; set; }
        public int Seconds { get; set; }
            
        public int Checked { get; set; }
        public Question(string text, List<string> answers, int correctAnswerIndex, int points)
        {
            Text = text;
            Answers = answers;
            CorrectAnswerIndex = correctAnswerIndex;
            Points = points;
        }
    }
}