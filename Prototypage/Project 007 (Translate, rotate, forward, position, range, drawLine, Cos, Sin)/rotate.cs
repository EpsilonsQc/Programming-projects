using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class rotate : MonoBehaviour
{
    [SerializeField] private int rotateSpeed;

    // Update is called once per frame
    void Update()
    {
        // Move the attached gameObject (cube) of +1 Z-Axis on each frame update
        transform.Rotate(new Vector3(0, 1, 0) * Time.deltaTime * rotateSpeed);
    }
}