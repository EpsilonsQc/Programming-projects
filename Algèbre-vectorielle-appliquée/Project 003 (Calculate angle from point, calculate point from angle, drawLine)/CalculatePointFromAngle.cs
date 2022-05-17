using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CalculatePointFromAngle : MonoBehaviour
{
    [SerializeField] private float angleInDegree = default;
    [SerializeField] private float length = default;
    [SerializeField] private Vector2 origin = default;
    [SerializeField] private GameObject MySphere = default;
    [SerializeField] private GameObject MyCube = default;

    private void Update()
    {
        MyCube.transform.position = origin;

        float angleInRad = degToRad(angleInDegree);
        MySphere.transform.position = CalculCoord(origin, angleInRad, length) + origin;
    }

    private Vector2 CalculCoord(Vector2 origin, float angle, float distance)
    {
        Vector2 p = new Vector2();

        p.x = origin.x + distance * Mathf.Cos(angle);
        p.y = origin.y + distance * Mathf.Sin(angle); 

        return p;
    }

    private float degToRad(float angle)
    {
        return angle * Mathf.PI / 180f;
    }
}