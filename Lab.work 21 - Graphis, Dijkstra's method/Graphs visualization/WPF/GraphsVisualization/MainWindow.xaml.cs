using System;
using System.Windows;

namespace GraphsVisualization
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

        private GraphDrawer _drawer;

        private void ButtonBase_OnClick(object sender, RoutedEventArgs e)
        {
            if (_drawer != null)
                _drawer.ClearCanvas();

            var numbers = ElementDataTextBox.Text.Split(new char[] { ';', ',' }, StringSplitOptions.RemoveEmptyEntries);

            var itemsCount = Convert.ToInt32(Math.Sqrt(numbers.Length));
            var graphData = new double[itemsCount, itemsCount];
            var startIndex = Convert.ToInt32(FirstElementTextBox.Text) - 1;
            var finishIndex = Convert.ToInt32(SecondElemetTextBox.Text) - 1;

            int index = -1;

            for (int i = 0; i < itemsCount; i++)
                for (int j = 0; j < itemsCount; j++)
                {
                    index++;
                    graphData[i, j] = Convert.ToDouble(numbers[index]);
                }

            _drawer = new GraphDrawer(graphData, GraphCanvas);
            _drawer.DrawGraph();

            var navigator = new GraphNavigator();
            navigator.FindShortestRanges(graphData, startIndex, itemsCount);
            RootLengthTextBox.Text = navigator.Distance[finishIndex].ToString();
        }
    }
}
