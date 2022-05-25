using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CharacterController6 : MonoBehaviour
{
    [SerializeField] private float moveSpeed = 5f;
    [SerializeField] private float rotationSpeed = 100f;

    // Update is called once per frame
    void Update()
    {
        float mouseX = (Input.mousePosition.x - Screen.width / 2) / Screen.width / 2 * rotationSpeed;
        float horizontalInput = Input.GetAxis("Horizontal");
        float verticalInput = Input.GetAxis("Vertical");

        transform.Rotate(new Vector3(0,mouseX,0) * Time.deltaTime);
        transform.Translate(new Vector3(horizontalInput, 0, verticalInput) * moveSpeed * Time.deltaTime);
    }
}