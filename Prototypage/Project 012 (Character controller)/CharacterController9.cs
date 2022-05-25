using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CharacterController9 : MonoBehaviour
{
    [SerializeField] private float moveSpeed = 5f;
    [SerializeField] private float rotationSpeed = 10f;

    // Update is called once per frame
    void Update()
    {
        float mouseX = (Input.mousePosition.x - Screen.width / 2) / Screen.width / 2 * rotationSpeed;
        float mouseY = -(Input.mousePosition.y - Screen.height / 2) / Screen.height / 2 * rotationSpeed;
        float horizontalInput = Input.GetAxis("Horizontal");
        float verticalInput = Input.GetAxis("Vertical");
        
        transform.Rotate(new Vector3(0, mouseX, 0) * Time.deltaTime, Space.World);
        transform.Rotate(new Vector3(mouseY, 0, 0) * Time.deltaTime, Space.Self);
        
        float clampxRotation = transform.localEulerAngles.x;

        if (clampxRotation > 180) 
        {
            clampxRotation -= 360;
        }

        clampxRotation = Mathf.Clamp(clampxRotation, -20, 20);

        if (clampxRotation <= 0)
        {
            clampxRotation += 360;
        }

        transform.rotation = Quaternion.Euler(clampxRotation, transform.localEulerAngles.y, transform.localEulerAngles.z);      
        transform.Translate(new Vector3(horizontalInput, 0, verticalInput) * moveSpeed * Time.deltaTime);
    }
}