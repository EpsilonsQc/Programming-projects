using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Gravity : MonoBehaviour
{
    [Header("ON/OFF")]
    [SerializeField] private bool applyGravity;
    [Space(15)]
    [Header("GRAVITY")]
    [SerializeField] private float maxFallingSpeed = 0.5f;
    private float actualSpeed;

    // Update is called once per frame
    void Update()
    {
        ApplyGravity();
    }

    void ApplyGravity()
    {
        if(applyGravity == true)
        {
            actualSpeed -= Mathf.Abs(maxFallingSpeed) * Time.deltaTime;
            transform.position += new Vector3(0, actualSpeed, 0);

            // if (actualSpeed < -Mathf.Abs(maxFallingSpeed))
            // {
                // actualSpeed = Mathf.Clamp(actualSpeed, -Mathf.Abs(maxFallingSpeed), 0); // Mathf.Clamp(xValue, xMin, xMax)
                // actualSpeed = -Mathf.Clamp(Mathf.Abs(actualSpeed), 0, Mathf.Abs(maxFallingSpeed)); // Mathf.Clamp(xValue, xMin, xMax)
            // } 
        }
    }
}