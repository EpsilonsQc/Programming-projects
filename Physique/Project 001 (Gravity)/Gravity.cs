using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Gravity : MonoBehaviour
{
    [SerializeField] private float mass = 1f; // Mass of the object

    private Vector3 vGravity = new Vector3(0f, -9.81f, 0f); // Gravity
    
    private Vector3 position = default; // Position
    private Vector3 velocity = default; // Velocity

    private Vector3 acceleration = default; // Acceleration
    private Vector3 gravityForce = default; // Gravity force

    private float speed = 0.0f; // Speed
    private Vector3 normalVelocity = default; // Normal velocity

    private void Awake()
    {
        position = transform.position; // Set position
        velocity = Vector3.zero; // Set velocity
        acceleration = Vector3.zero; // Set acceleration
    }

    private void Update()
    {
        // Calculate gravity force
        gravityForce = mass * vGravity;

        // Calculate the acceleration
        acceleration = gravityForce / mass;

        // If the object is above the ground
        if(position.y > 0.0f)
        {
            velocity = velocity + acceleration * Time.deltaTime; // Calculate the velocity
            position = position + velocity * Time.deltaTime; // Calculate the position
        }

        // Calculate the speed
        speed = velocity.magnitude;

        // Calculate the normal velocity
        normalVelocity = velocity.normalized;

        // Debug Logs
        Debug.Log("Speed: " + speed + " Normal Velocity: " + normalVelocity);

        // Set the position of the object
        transform.position = position;
    }
}