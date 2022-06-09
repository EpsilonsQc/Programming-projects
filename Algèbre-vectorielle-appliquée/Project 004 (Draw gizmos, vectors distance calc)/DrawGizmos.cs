using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;

public class DrawGizmos : MonoBehaviour
{
    void OnDrawGizmos()
    {
        Handles.color = VectorsDistanceCalc.staticWireDiscColor;
        Handles.DrawWireDisc(transform.position, Vector3.forward, VectorsDistanceCalc.staticWireDiscRadius);

        Debug.DrawRay(transform.position, VectorsDistanceCalc.staticVectorToTarget * VectorsDistanceCalc.staticRayLength, VectorsDistanceCalc.staticRayColor);
    }
}