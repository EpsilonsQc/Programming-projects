using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using MyDebug;

public class DrawKite : MonoBehaviour
{
    // Line width
    [Header("LINE WIDTH")]
    [SerializeField] private float lineWidth = 0.5f;

    // Kite origin
    Vector2 kiteOrigin = new Vector2(20f, 40f);

    // P1
    static float p1y = Mathf.Cos(DegToRad(56)) * 32;
    static float p1x = Mathf.Sqrt((32 * 32 - p1y * p1y));
    Vector2 p1 = new Vector2(Mathf.Abs(p1x),Mathf.Abs(p1y));

    // P2
    static float p2x = Mathf.Cos(DegToRad(10)) * 32;
    static float p2y = Mathf.Sqrt((32 * 32 - p2x * p2x));
    Vector2 p2 = new Vector2(Mathf.Abs(p2x),Mathf.Abs(p2y));

    // P3
    static float p3x = Mathf.Cos(DegToRad(22)) * 40;
    static float p3y = Mathf.Sqrt((40 * 40 - p3x * p3x));
    Vector2 p3 = new Vector2(Mathf.Abs(p3x),Mathf.Abs(p3y));

    // Convert degree to radiant
    static float DegToRad(float degree)
    {
        float radiant = degree * 3.1416f / 180f;
        return radiant;
    }

    // Calculate angle, direction of vectors and draw kite segments
    void RenderKite()
    {
        // Blue line
        Segment.DrawNewSegment(kiteOrigin, p1 + kiteOrigin, lineWidth, Color.blue);
        Segment.DrawNewSegment(kiteOrigin, p2 + kiteOrigin, lineWidth, Color.blue);
        Segment.DrawNewSegment(p3 + kiteOrigin, p2 + kiteOrigin, lineWidth, Color.blue);
        Segment.DrawNewSegment(p3 + kiteOrigin, p1 + kiteOrigin, lineWidth, Color.blue);

        // Red line
        Segment.DrawNewSegment(kiteOrigin, p3 + kiteOrigin, lineWidth, Color.red);
        Segment.DrawNewSegment(p1 + kiteOrigin, p2 + kiteOrigin, lineWidth, Color.red);
    }

    // Start is called before the first frame update
    void Start()
    {
        Debug.Log("P1: " + p1);
        Debug.Log("P2: " + p2);
        Debug.Log("P3: " + p3);
        RenderKite();
    }
}