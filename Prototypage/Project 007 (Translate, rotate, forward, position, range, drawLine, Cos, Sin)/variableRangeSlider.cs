using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class variableRangeSlider : MonoBehaviour
{
    // This integer will be shown as a slider, with the range of 0 to 100 in the inspector
    [SerializeField] [Range(0, 100)] private int integerRange;

    // This float will be shown as a slider, with the range of 0.0f to 1.0f in the inspector
    [SerializeField] [Range(0.0f, 1.0f)] private float floatRange;
}