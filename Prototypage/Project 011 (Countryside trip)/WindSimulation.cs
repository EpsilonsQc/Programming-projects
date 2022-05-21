using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class WindSimulation : MonoBehaviour
{
    private float windSpeed = 0.01f; // Define wind intensity

    // Update is called once per frame
    void Update()
    {
        windSimulation();
    }

    void windSimulation()
    {
        float windEffect = Mathf.Cos(Time.time) * windSpeed;

        transform.Rotate(windEffect, windEffect, windEffect, Space.Self);
    }
}