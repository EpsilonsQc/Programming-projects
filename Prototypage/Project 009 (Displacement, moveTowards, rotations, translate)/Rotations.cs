using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Rotations : MonoBehaviour
{
    [Header("VARIOUS ROTATIONS")]
    [SerializeField] private bool rotationQuaternionEuler;
    [SerializeField] private bool rotationEuler;
    [SerializeField] private bool rotateWorld;
    [SerializeField] private bool rotateSelf;
    [SerializeField] private bool rotateAround;
    [SerializeField] private bool rotateAroundObject;
    [SerializeField] private bool rotateAroundAxis;
    [SerializeField] private bool ellipticalDisplacementSinCos;
    [Space(15)]
    [SerializeField] private int moveSpeed;
    [SerializeField] private int distance = 1;
    [SerializeField] private Vector3 axis;
    [SerializeField] private GameObject MyTarget;

    void Start()
    {
        // Get the axis between objects
        axis = Vector3.Cross(transform.position, MyTarget.transform.position).normalized;
    }

    // Update is called once per frame
    void Update()
    {
        rotationQuaternionEulerF();
        rotationEulerF();
        rotateWorldF();
        rotateSelfF();
        rotateAroundF();
        rotateAroundObjectF();
        rotateAroundAxisF();
        ellipticalDisplacementSinCosF();
    }

    // Rotate a gameObject with "Quaternion Euler"
    void rotationQuaternionEulerF()
    {
        float speed = moveSpeed * Time.deltaTime;

        if (rotationQuaternionEuler == true)
        {
            transform.rotation = transform.rotation * Quaternion.Euler(0, speed, 0);
            Debug.Log("Quaternion Euler: " + Quaternion.Euler(0, speed, 0));
        }
    }

    // Rotate a gameObject with "eulerAngles"
    void rotationEulerF()
    {
        float speed = moveSpeed * Time.deltaTime;

        if (rotationEuler == true)
        {
            transform.eulerAngles += Vector3.up * speed;
        }
    }

    // Rotate a gameObject with "Rotate" (World Space)
    void rotateWorldF()
    {
        float speed = moveSpeed * Time.deltaTime;

        if (rotateWorld == true)
        {
            transform.Rotate(Vector3.up * speed, Space.World);
        }
    }

    // Rotate a gameObject with "Rotate" (Self Space - locale)
    void rotateSelfF()
    {
        float speed = moveSpeed * Time.deltaTime;

        if (rotateSelf == true)
        {
            transform.Rotate(Vector3.up * speed, Space.Self);
        }
    }

    // Rotate a gameObject with "Rotate Around" around zero (world pos)
    void rotateAroundF()
    {
        float speed = moveSpeed * Time.deltaTime;

        if (rotateAround == true)
        {
            transform.RotateAround(Vector3.zero, Vector3.up, speed);
        }
    }

    // Rotate a gameObject with "Rotate Around" around target gameObject
    void rotateAroundObjectF()
    {
        float speed = moveSpeed * Time.deltaTime;

        if (rotateAroundObject == true)
        {
            transform.RotateAround(MyTarget.transform.position, Vector3.up, speed);
        }
    }

    // Rotate a gameObject with "Rotate Around" around target gameObject axis
    void rotateAroundAxisF()
    {
        float speed = moveSpeed * Time.deltaTime;

        if (rotateAroundAxis == true)
        {
            transform.RotateAround(MyTarget.transform.position, axis, speed);
        }
    }

    // Rotate a gameObject with Mathf Cos and Sin
    void ellipticalDisplacementSinCosF()
    {
        float x = Mathf.Sin(Time.time * moveSpeed);
        float y = 0;
        float z = Mathf.Cos(Time.time * moveSpeed);

        if (ellipticalDisplacementSinCos == true)
        {
            transform.position = new Vector3(x, y, z) * distance;
        }
    }
}