using System.Collections; 
using System.Collections.Generic;
using UnityEngine;

public class Interpolation : MonoBehaviour
{
    
    [Header("LERP - VECTORS")]
    [SerializeField] Vector3 startPosition;
    [SerializeField] Vector3 endPosition;
    [Space(10)]

    [Header("LERP - FLOATS")]
    [SerializeField] float startValue;
    [SerializeField] float endValue;
    [Space(10)]

    [Header("VARIABLES")]
    [SerializeField] float time; // duration in seconds of the interpolation
    [SerializeField] float timeCounter;
    [Space(10)]
    [SerializeField] float distanceCoveredPercentage; // Percentage of distance covered by the interpolation
    [SerializeField] float interpolationValue; // The parameter is clamped to the range [0, 1]

    void Awake()
    {
        startPosition = transform.position;
        endPosition = new Vector3(100, 0 ,0);

        time = 5f;
        timeCounter = 0f;
    }

    void Update()
    {
        timeCounter += Time.deltaTime;
        interpolationValue = timeCounter / time;

        distanceCoveredPercentage = (interpolationValue * 100);

        if(interpolationValue >= 1f)
        {
            timeCounter = 0f;
            return;
        }

        transform.position = LerpWithVector(startPosition, endPosition, interpolationValue);
    }

    // Float Linear interpolation (also known as "lerp")
    public float LerpWithFloat(float start, float end, float t)
    {
        return ( start + ( end - start ) * t );
    }

    // Vector3 Linear interpolation (also known as "lerp")
    public Vector3 LerpWithVector(Vector3 start, Vector3 end, float t)
    {
        return ( start + ( end - start ) * t );
    }
}
