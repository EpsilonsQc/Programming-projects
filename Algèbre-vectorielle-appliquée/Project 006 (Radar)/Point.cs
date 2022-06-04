using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace MyDebug
{
    public class Point
    {
        static int ID = 0;

        // Draws a Point at a specified coordinate.
        public static GameObject DrawNewPoint(Vector2 Position, float width, Color color)
        {
            GameObject newPoint = new GameObject("Point" + "(" + ID + ")");
            LineRenderer pointRenderer = newPoint.AddComponent<LineRenderer>();
            pointRenderer.material = new Material(Shader.Find("Unlit/Color"));
            pointRenderer.material.color = color;

            DrawPoint(pointRenderer, Position, width);
            ID += 1;
            return newPoint;
        }

        private static void DrawPoint(LineRenderer pointRenderer, Vector2 pos, float width)
        {
            pointRenderer.positionCount = 2;
            pointRenderer.SetPosition(0, new Vector2(pos.x - width / 3f, pos.y - width / 3f));
            pointRenderer.SetPosition(1, new Vector2(pos.x + width / 3f, pos.y + width / 3f));
            pointRenderer.startWidth = width;
            pointRenderer.endWidth = width;
        }
    }
}