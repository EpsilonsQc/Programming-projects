using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using MyDebug;

public class DrawAxes : MonoBehaviour
{
    [SerializeField] float lineWidth;

    [SerializeField] Vector2 axeX_start;
    [SerializeField] Vector2 axeX_end;

    [SerializeField] Vector2 axeY_start;
    [SerializeField] Vector2 axeY_end;

    private void Start()
    {
        Segment.DrawNewSegment(axeX_start, axeX_end, lineWidth, Color.red);
        Segment.DrawNewSegment(axeY_start, axeY_end, lineWidth, Color.green);
    }
}