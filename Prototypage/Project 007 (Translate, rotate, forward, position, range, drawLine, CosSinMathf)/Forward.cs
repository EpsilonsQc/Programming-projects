using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Forward : MonoBehaviour
{
    [SerializeField] private int forwardSpeed;

    // Update is called once per frame
    void Update()
    {
        // Move the attached gameObject (cube) on each frame update
        // Forward is a shorthand for writing Vector3(0, 0, 1)
        transform.Translate(transform.forward * Time.deltaTime * forwardSpeed, Space.World);
    }
}