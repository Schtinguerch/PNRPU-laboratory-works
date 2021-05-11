using System;
using System.Collections.Generic;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Shapes;

namespace GraphsVisualization
{
    class GraphDrawer
    {
        private Canvas _canvas;

        private List<Ellipse> _ellipses;

        private List<TextBlock> _names;

        private List<TextBlock> _lengths;

        private List<GraphEdge> _lines;

        private List<Polygon> _arrows;

        private List<Point> _points;

        public List<List<double>> GraphData { get; set; }

        public GraphDrawer(double[,] graphData, Canvas theCanvas)
        {
            GraphData = new List<List<double>>();
            var count = (int) Math.Sqrt(graphData.Length);

            for (int i = 0; i < count; i++)
            {
                var newList = new List<double>();
                for (int j = 0; j < count; j++)
                    newList.Add(graphData[i, j]);

                GraphData.Add(newList);
            }

            _canvas = theCanvas;
        }

        public void ClearCanvas()
        {
            _canvas.Children.Clear();
            _ellipses.Clear();
            _names.Clear();
            _lines.Clear();
            _lengths.Clear();
            _arrows.Clear();
        }

        public void DrawGraph()
        {
            _ellipses = new List<Ellipse>();
            _names = new List<TextBlock>();
            _points = new List<Point>();
            _lines = new List<GraphEdge>();
            _lengths = new List<TextBlock>();
            _arrows = new List<Polygon>();

            if (_canvas != null)
            {
                var circleRadius = 300d;
                var centerPoint = new Point(450, 400);

                var offset = 2 * circleRadius / (GraphData.Count - 1);
                var miltiplier = 1d;

                for (int i = 0; i < GraphData.Count; i++)
                {
                    miltiplier *= -1;

                    var positionX = offset * i - circleRadius;
                    var positionY = miltiplier * Math.Sqrt(Math.Pow(circleRadius, 2d) - Math.Pow(positionX, 2d));

                    var drawPoint = new Point(positionX + centerPoint.X, positionY + centerPoint.Y);
                    _points.Add(drawPoint);
                }

                for (int i = 0; i < GraphData.Count; i++)
                    for (int j = 0; j < GraphData[i].Count; j++)
                        if (GraphData[i][j] != 0)
                            AddGraphLine(i, j);
                        

                for (int i = 0; i < _lengths.Count - 1; i++)
                    for (int j = i + 1; j < _lengths.Count; j++)
                    {
                        if (ArePointsEquals(_lengths[i], _lengths[j]))
                            Canvas.SetTop(_lengths[i], Canvas.GetTop(_lengths[i]) - 30d);
                    }
                

                for (int i = 0; i < GraphData.Count; i++)
                    AddGraph(_points[i], (i + 1).ToString());
            }
            else
            {
                MessageBox.Show("The canvas is a null-object");
            }
        }

        private void AddGraph(Point drawPoint, string text)
        {
            var GraphItem = new Ellipse()
            {
                Fill = new SolidColorBrush(Colors.Aquamarine),
                Width = 60,
                Height = 60,
                Stroke = new SolidColorBrush(Colors.CadetBlue),
                StrokeThickness = 2d,
            };

            var textBlockItem = new TextBlock()
            {
                Text = text,
                FontSize = 16d,
            };

            Canvas.SetLeft(GraphItem, drawPoint.X);
            Canvas.SetTop(GraphItem, drawPoint.Y);
            _canvas.Children.Add(GraphItem);
            _ellipses.Add(GraphItem);

            Canvas.SetLeft(textBlockItem, drawPoint.X + 26);
            Canvas.SetTop(textBlockItem, drawPoint.Y + 18);
            _canvas.Children.Add(textBlockItem);
            _names.Add(textBlockItem);
        }

        private void AddGraphLine(int i, int j)
        {
            var graphLine = new GraphEdge()
            {
                Source = new Point(_points[i].X + 30, _points[i].Y + 30),
                Destination = new Point(_points[j].X + 30, _points[j].Y + 30),
            };

            var lengthText = new TextBlock()
            {
                Text = GraphData[i][j].ToString(),
                FontSize = 16d,
            };

            Canvas.SetTop(lengthText, (graphLine.Source.Y + graphLine.Destination.Y) / 2d + 15);
            Canvas.SetLeft(lengthText, (graphLine.Source.X + graphLine.Destination.X) / 2d - 15);

            _lengths.Add(lengthText);
            _canvas.Children.Add(lengthText);

            _lines.Add(graphLine);
            _canvas.Children.Add(graphLine);

            var arrow = new Polygon()
            {
                Points = new PointCollection()
                {
                    new Point(-50, -10),
                    new Point(-20, 0),
                    new Point(-50, 10),
                },
                Fill = Brushes.DarkGray,
                RenderTransform = new RotateTransform(Math.Atan2(graphLine.Destination.Y - graphLine.Source.Y, graphLine.Destination.X - graphLine.Source.X) * 57.3)
            };

            Canvas.SetTop(arrow, graphLine.Destination.Y);
            Canvas.SetLeft(arrow, graphLine.Destination.X);

            _arrows.Add(arrow);
            _canvas.Children.Add(arrow);
        }

        private bool ArePointsEquals(TextBlock first, TextBlock second)
        {
            var areEquals = false;
            if (Math.Abs(Canvas.GetTop(first) - Canvas.GetTop(second)) <= 1d)
                if (Math.Abs(Canvas.GetLeft(first) - Canvas.GetLeft(second)) <= 1d)
                    areEquals = true;

            return areEquals;
        }
    }
}
