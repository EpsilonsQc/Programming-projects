using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CharacterController3 : MonoBehaviour
{
    [SerializeField] private float moveSpeed = 5f;

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKey(KeyCode.RightArrow)) transform.position += Time.deltaTime * moveSpeed * Vector3.right;
        if (Input.GetKey(KeyCode.LeftArrow)) transform.position += Time.deltaTime * moveSpeed * Vector3.left;
        if (Input.GetKey(KeyCode.UpArrow)) transform.position += Time.deltaTime * moveSpeed * Vector3.forward;
        if (Input.GetKey(KeyCode.DownArrow)) transform.position += Time.deltaTime * moveSpeed * Vector3.back;
    }
}