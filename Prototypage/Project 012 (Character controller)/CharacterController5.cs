using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CharacterController5 : MonoBehaviour
{
    [SerializeField] private float moveSpeed = 5f;
    [SerializeField] private float rotationSpeed = 100f;

    // Update is called once per frame
    void Update()
    {
        float horizontalInput = Input.GetAxis("Horizontal");
        float verticalInput = Input.GetAxis("Vertical");

        transform.Rotate(new Vector3(0,horizontalInput,0) * rotationSpeed * Time.deltaTime);
        transform.Translate(new Vector3(0, 0, verticalInput) * moveSpeed * Time.deltaTime);
    }
}