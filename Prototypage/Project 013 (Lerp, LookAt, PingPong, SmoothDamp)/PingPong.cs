using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PingPong : MonoBehaviour
{
    [SerializeField] private float interpolationRatio;
    [SerializeField] private float moveSpeed = 0.5f;
    [SerializeField] private Vector3 positionA;
    [SerializeField] private Vector3 positionB;

    // Update is called once per frame
    void Update()
    {
        interpolationRatio = Mathf.PingPong(Time.time * moveSpeed, 1);
        gameObject.transform.position = Vector3.Lerp(positionA, positionB, interpolationRatio);
    }
}