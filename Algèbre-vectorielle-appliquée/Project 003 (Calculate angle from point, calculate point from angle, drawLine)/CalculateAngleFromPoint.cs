using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CalculateAngleFromPoint : MonoBehaviour
{
    [SerializeField] private Vector2 position = default;
    [SerializeField] private GameObject MySphere;

    private void Update()
    {
        MySphere.transform.position = position;

        float angleInRad = CalculateAngleWithSin(position);
        float angleInDegree = RadToDeg(angleInRad);

        Debug.Log("Angle in degree: " + angleInDegree);
    }

    private float CalculateAngleWithSin(Vector2 p)
    {
        float sinAngle = p.y / hypotenuse(p.x, p.y);
        float angle = Mathf.Asin(sinAngle);

        return angle;
    }

    private float CalculateAngleWithTan(Vector2 p)
    {
        // float tanAngle = coté opposé / coté adjacent
        float tanAngle = p.y / hypotenuse(p.x, p.y);
        float angle = Mathf.Atan(tanAngle);

        return angle;
    }

    private float hypotenuse(float dx, float dy)
    {
        float magn_2 = dx * dx + dy * dy;
        return Mathf.Sqrt(magn_2);
    }

    private float hypotenuse(Vector2 dp)
    {
        float magn_2 = dp.x * dp.x + dp.y * dp.y;
        return Mathf.Sqrt(magn_2);
    }

    private float RadToDeg(float angleInRadian)
    {
        return (angleInRadian * 180f / Mathf.PI);
    }
}