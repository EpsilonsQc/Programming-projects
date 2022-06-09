using System.Collections; 
using System.Collections.Generic;
using UnityEngine;

public class Interpolation : MonoBehaviour
{
    [Header("VECTORS")]
    [SerializeField] Vector3 startPosition;
    [SerializeField] Vector3 endPosition;
    [Space(10)]

    [Header("VARIABLES")]
    [SerializeField] float time; // duration in seconds of the interpolation
    [SerializeField] float deltaTimeCounter;
    [Space(10)]
    [SerializeField] float distanceCoveredPercentage; // Percentage of distance covered by the interpolation
    [SerializeField] float interpolationRatio; // This parameter is clamped to the range [0, 1]
    [Space(10)]
    [SerializeField] bool loopLerp;
    [SerializeField] bool pauseLerp;
    [SerializeField] bool resetLerp;

    void Awake()
    {
        startPosition = transform.position;
        endPosition = new Vector3(100, 0 ,0);

        time = 2.5f; // duration in seconds of the interpolation between two points
        deltaTimeCounter = 0f;

        loopLerp = false;
        pauseLerp = true;
        resetLerp = false;
    }

    void Update()
    {
        if(deltaTimeCounter <= time && pauseLerp == false && resetLerp == false)
        {
            deltaTimeCounter += Time.deltaTime;
            interpolationRatio = deltaTimeCounter / time;
            distanceCoveredPercentage = (interpolationRatio * 100);

            if(interpolationRatio <= 1f && pauseLerp == false && resetLerp == false)
            {
                transform.position = LerpWithVector(startPosition, endPosition, interpolationRatio);
            }
        }

        if (interpolationRatio >= 1f && loopLerp == true)
        {
            transform.position = startPosition;
            deltaTimeCounter = 0f;
            resetLerp = false;
        }

        if(resetLerp == true)
        {
            transform.position = startPosition;
            deltaTimeCounter = 0f;
            resetLerp = false;
        }
    }

    // Linear interpolation (also known as "lerp"). Move an object gradually between two points
    Vector3 LerpWithVector(Vector3 start, Vector3 end, float t)
    {
        return (start + (end - start) * t);
    }
}
