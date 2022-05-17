using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CosSinMathf : MonoBehaviour
{
    [SerializeField] private int waveDistanceMultiplier;
    [SerializeField] private int circleDistanceMultiplier;

    // Update is called once per frame
    void Update()
    {
        float X = Mathf.Cos(Time.time);
        float Y = Mathf.Sin(Time.time);

        // Move in wave
        transform.Translate(new Vector3(0, Y, 0) * Time.deltaTime * waveDistanceMultiplier);

        // Move in circle
        transform.Translate(new Vector3(X, Y, 0) * Time.deltaTime * circleDistanceMultiplier);
    }
}