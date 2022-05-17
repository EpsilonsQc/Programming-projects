using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Translate : MonoBehaviour
{
    [SerializeField] private int moveSpeed;

    // Update is called once per frame
    void Update()
    {
        // Move the attached gameObject (cube) of +1 Z-Axis on each frame update
        transform.Translate(new Vector3(0, 0, 1) * Time.deltaTime * moveSpeed);
    }
}