using System.Collections; 
using System.Collections.Generic;
using UnityEngine;

public class SmoothDamp : MonoBehaviour
{
    [SerializeField] private float timeToReachTarget;
    [SerializeField] private Vector3 positionA;
    private Vector3 velocity = Vector3.zero;

    // Update is called once per frame
    void Update()
    {
        transform.position = Vector3.SmoothDamp(transform.position, positionA, ref velocity, timeToReachTarget);
    }
}
