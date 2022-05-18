using System.Collections; 
using System.Collections.Generic;
using UnityEngine;

public class ShapeShift : MonoBehaviour
{
    // Update is called once per frame
    void Update()
    {
        transform.localScale += new Vector3(Mathf.Sin(Time.time), 0, Mathf.Sin(Time.time)); // Change the scale of the gameObject attached to this script
    }
}
