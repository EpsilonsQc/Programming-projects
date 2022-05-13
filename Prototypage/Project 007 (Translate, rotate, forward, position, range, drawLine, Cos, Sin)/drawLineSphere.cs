using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class drawLineSphere : MonoBehaviour
{
    // Update is called once per frame
    void Update()
    {
        // Draw multiple lines creating a sphere with a lifespan of 2.5s for each line
        Debug.DrawLine(Random.onUnitSphere * 10, Random.onUnitSphere * 10,  Color.white, 2.5f);
    }
}