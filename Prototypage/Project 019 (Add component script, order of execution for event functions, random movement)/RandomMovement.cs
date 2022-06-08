using System.Collections; 
using System.Collections.Generic;
using UnityEngine;

public class RandomMovement : MonoBehaviour
{
    [Header("VECTORS")]
    [SerializeField] Vector3 actualDirection;
    [SerializeField] Vector3 newDirection;
    [Space(5)]

    [Header("QUATERNIONS")]
    [SerializeField] Quaternion actualRotation;
    [SerializeField] Quaternion newRotation;
    [Space(5)]

    [Header("SPEED")]
    [SerializeField] float movementSpeed;
    [SerializeField] float rotationSpeed;
    [Space(5)]

    [Header("MOVEMENT RANGE")]
    [SerializeField] float movementRangeMin;
    [SerializeField] float movementRangeMax;
    [Space(5)]

    [Header("INVOKE RATE")]
    [SerializeField] float invokeStartTime;
    [SerializeField] float invokeRateMin;
    [SerializeField] float invokeRateMax;
    [Space(5)]

    [Header("LERP INTERPOLATION RATIO")]
    [SerializeField] float lerpInterpolationRatio;

    void Awake()
    {
        newDirection = Vector3.zero;

        movementSpeed = 100f;
        rotationSpeed = 3f;

        movementRangeMin = -1000f;
        movementRangeMax = 1000f;

        invokeStartTime = 0f;
        invokeRateMin = 3f;
        invokeRateMax = 10f;

        lerpInterpolationRatio = 0f;
    }

    void Update()
    {
        if(Input.GetKeyDown("space"))
        {
            if(IsInvoking("ChangePosition"))
            {
                CancelInvoke("ChangePosition");
            }
            else
            {
                InvokeRepeating("ChangePosition", invokeStartTime, Random.Range(invokeRateMin, invokeRateMax));
            }
        }

        lerpInterpolationRatio += rotationSpeed * Time.deltaTime; 
        transform.rotation = Quaternion.Lerp(actualRotation, newRotation, lerpInterpolationRatio);
        transform.position = Vector3.MoveTowards(transform.position, newDirection, Time.deltaTime * movementSpeed);
    }

    void ChangePosition()
    {
        newDirection = new Vector3(Random.Range(movementRangeMin, movementRangeMax), 0f, Random.Range(movementRangeMin, movementRangeMax));
        actualDirection = Vector3.Normalize(newDirection - transform.position);

        newRotation = Quaternion.LookRotation(actualDirection, Vector3.up);  
        actualRotation = transform.rotation;
        lerpInterpolationRatio = 0f;
    }
}
