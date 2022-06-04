using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace MyDebug
{
    public class Segment
    {
        static int ID = 0;

        // Draws a line between specified start and end points.
        public static void DrawNewSegment(Vector2 startPoint, Vector2 endPoint, float width, Color color)
        {
            GameObject newAxe = new GameObject("Axe"+ "("+ID+")");
            LineRenderer lineRenderer = newAxe.AddComponent<LineRenderer>();
            lineRenderer.material = new Material(Shader.Find("Unlit/Color"));
            lineRenderer.material.color = color;

            DrawLine(lineRenderer, startPoint, endPoint, width);
            ID += 1;
        }

        private static void DrawLine(LineRenderer lineRenderer, Vector2 startPoint, Vector2 endPoint, float width)
        {
            lineRenderer.positionCount = 2;
            lineRenderer.SetPosition(0, startPoint);
            lineRenderer.SetPosition(1, endPoint);
            lineRenderer.startWidth = width;
            lineRenderer.endWidth = width;
        }
    }
}