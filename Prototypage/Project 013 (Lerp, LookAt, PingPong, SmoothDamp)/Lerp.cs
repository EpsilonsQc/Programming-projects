using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Lerp : MonoBehaviour
{
    [SerializeField] private float interpolationRatio;
    [SerializeField] private float moveSpeed = 0.1f;
    [SerializeField] private Vector3 positionA;
    [SerializeField] private Vector3 positionB;

    // Update is called once per frame
    void Update()
    {
        interpolationRatio += Time.deltaTime * moveSpeed;
        interpolationRatio = Mathf.Clamp(interpolationRatio, 0 , 1);

        gameObject.transform.position = Vector3.Lerp(positionA, positionB, interpolationRatio);
    }
}