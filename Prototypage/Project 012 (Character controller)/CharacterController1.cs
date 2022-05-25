using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CharacterController1 : MonoBehaviour
{
    [SerializeField] private float moveSpeed = 5f;

    // Update is called once per frame
    void Update()
    {
        float horizontalInput = Input.GetAxis("Horizontal");
        float verticalInput = Input.GetAxis("Vertical");

        Debug.Log("Axe horizontal" + horizontalInput);
        Debug.Log("Axe vertical" + verticalInput);

        transform.Translate(new Vector3(horizontalInput, 0, verticalInput) * Time.deltaTime * moveSpeed);
    }
}