namespace Прыжки_спортсменов
{
    public class Score
    {
        public double Difficult { get; set; }
        public List<double> JudgesS { get; set; }

        public Score(double difficult, List<double> judgesS)
        {
            if (judgesS.Count != 5)
                throw new ArgumentException("Всего должно быть ровно 5 судейских оценок.");

            Difficult = difficult;
            JudgesS = judgesS;
        }

        public double FinalScore()
        {
            if (JudgesS.Count != 5)
                throw new InvalidOperationException("Всего должно быть ровно 5 судейских оценок.");

            var sortedS = JudgesS.OrderBy(score => score).ToList();
            double finalS = sortedS.Skip(1).Take(3).Sum() * Difficult;
            return finalS;
        }
    }
}
