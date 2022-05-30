using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraFollow : MonoBehaviour
{
    [Header("CAMERA SETTINGS")]
    [SerializeField] Transform thisTransform; // Camera transform
    [SerializeField] Transform target; // Spaceship transform
    [Space(15)]
    [SerializeField] Vector3 offset = new Vector3(0f, 25f, -50f); // default offset from target
    [SerializeField] float positionDamping = 2.0f; // smoothing out the position (camera)

    /* ALTERNATIVE METHOD */ // private Vector3 velocity = Vector3.zero;

    void Start()
    {
        thisTransform = transform; // cache 'transform' component of the camera so it doesn't need to be looked up each frame.
    }

    void LateUpdate()
    {
        // Early out if we don't have a target
		if (!target) // if target == null
        {
            Debug.Log("[CAMERA] No target detected. Please add a target in the inspector.");
            return;
        }
        
        // control camera position in the world
        Vector3 wantedPosition = target.position + (target.rotation * offset);
        Vector3 currentPosition = Vector3.Lerp(thisTransform.position, wantedPosition, positionDamping * Time.deltaTime);
        /* ALTERNATIVE METHOD */ // Vector3 currentPosition = Vector3.SmoothDamp(transform.position, wantedPosition, ref velocity, positionDamping * Time.deltaTime);
        thisTransform.position = currentPosition;

        // control camera rotation in the world
        thisTransform.LookAt(target.position, target.up);
        /* ALTERNATIVE METHOD */ // Quaternion wantedRotation = Quaternion.LookRotation (target.position -  thisTransform.position, target.up);
        /* ALTERNATIVE METHOD */ // thisTransform.rotation = wantedRotation;
    }
}