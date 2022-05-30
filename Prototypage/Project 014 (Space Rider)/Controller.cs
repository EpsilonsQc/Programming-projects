using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Controller : MonoBehaviour
{
    [Header("CONTROLLER SETTINGS")]
    [SerializeField] Transform thisTransform;
    [Space(15)]
    [SerializeField] float moveSpeed = 25f;
    [SerializeField] float warpSpeed = 100f;
    [SerializeField] float rotationSpeed = 100f;

    [Header("PARTICLES FX")]
    [SerializeField] ParticleSystem ExhaustFX1;
    [SerializeField] ParticleSystem ExhaustFX2;
    [SerializeField] ParticleSystem ExhaustFX3;
    [SerializeField] ParticleSystem ExhaustFX4;

    void Start()
    {
        thisTransform = transform;
    }

    void Update()
    {
        float mouseY = Input.GetAxis("Mouse Y");
        thisTransform.Rotate(new Vector3(mouseY,0,0) * rotationSpeed * Time.deltaTime);

        float horizontalInput = Input.GetAxis("Horizontal");
        thisTransform.Rotate(new Vector3(0,horizontalInput,0) * rotationSpeed * Time.deltaTime);
        thisTransform.Translate(new Vector3(horizontalInput, 0, 0) * moveSpeed * Time.deltaTime);
        
        StationnaryFX();

        float verticalInput = Input.GetAxis("Vertical");
        if (Input.GetKey(KeyCode.LeftShift)) // warp speed
        {
            WarpSpeedFX();
            thisTransform.Translate(new Vector3(0, 0, verticalInput) * warpSpeed * Time.deltaTime);
        }
        else if (Input.GetKey(KeyCode.W)) // normal speed (forward)
        {
            NormalSpeedFX();
            thisTransform.Translate(new Vector3(0, 0, verticalInput) * moveSpeed * Time.deltaTime);
        }
        else if (Input.GetKey(KeyCode.S)) // normal speed (back)
        {
            NormalSpeedFX();
            thisTransform.Translate(new Vector3(0, 0, verticalInput) * moveSpeed * Time.deltaTime);
        }
    }

    void StationnaryFX()
    {
        var nFX1 = ExhaustFX1.main;
        var nFX2 = ExhaustFX2.main;
        var nFX3 = ExhaustFX3.main;
        var nFX4 = ExhaustFX4.main;
        
        nFX1.startSpeed = 0f;
        nFX2.startSpeed = 0f;
        nFX3.startSpeed = 0f;
        nFX4.startSpeed = 0f;
    }

    void NormalSpeedFX()
    {
        var FX1 = ExhaustFX1.main;
        var FX2 = ExhaustFX2.main;
        var FX3 = ExhaustFX3.main;
        var FX4 = ExhaustFX4.main;

        FX1.startSpeed = 5f;
        FX2.startSpeed = 5f;
        FX3.startSpeed = 5f;
        FX4.startSpeed = 5f;
    }

    void WarpSpeedFX()
    {
        var FX1 = ExhaustFX1.main;
        var FX2 = ExhaustFX2.main;
        var FX3 = ExhaustFX3.main;
        var FX4 = ExhaustFX4.main;

        FX1.startSpeed = 15f;
        FX2.startSpeed = 15f;
        FX3.startSpeed = 15f;
        FX4.startSpeed = 15f;
    }
}