using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;

public class DrawWireDisc : MonoBehaviour
{
    void OnDrawGizmos()
    {
        Handles.color = VectorsDistanceCalc.wireDiscColor;
        Handles.DrawWireDisc(transform.position, Vector3.forward, VectorsDistanceCalc.wireDiscRadius);    
    }
}