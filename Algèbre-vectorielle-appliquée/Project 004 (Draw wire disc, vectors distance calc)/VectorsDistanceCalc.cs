using System.Collections; 
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;

public class VectorsDistanceCalc : MonoBehaviour
{
    [Header("DRAW WIRE DISC")]
    [SerializeField] static public float wireDiscRadius = 75f;
    [SerializeField] static public Color wireDiscColor = Color.red;
    [Space(10)]

    [Header("GAME OBJECT")]
    [SerializeField] GameObject Mouse;
    [SerializeField] GameObject Cheese;
    [Space(10)]

    [Header("COMPONENT")]
    [SerializeField] SpriteRenderer spriteRenderer;
    [Space(10)]

    [Header("VECTORS")]
    [SerializeField] Vector3 currentPos;
    [SerializeField] private Vector3 vectorToTarget;
    [Space(10)]
    
    [Header("PARAMETERS")]
    [SerializeField] float movementSpeed = 100.0f;
    [SerializeField] float distanceOffset = 15.0f;
    [SerializeField] float rayLength = 15f;
    [Space(10)]

    [Header("COLOR")]
    [SerializeField] Color rayColor = Color.red;
    
    void Awake()
    {
        currentPos = transform.position;

        Mouse = GameObject.Find("Mouse");
        Cheese = GameObject.Find("Cheese");
        spriteRenderer = Mouse.GetComponent<SpriteRenderer>();

        if (Mouse == null)
        {
            Debug.LogWarning("[Mouse] not found!");
        }

        if (Cheese == null)
        {
            Debug.LogWarning("[Cheese] not found!");
        }

        if (spriteRenderer == null)
        {
            Debug.LogWarning("[Sprite Renderer] not found!");
        }
    }

    // Update is called once per frame
    void Update()
    {
        vectorToTarget = GetTargetDirection();

        if (IsCloseToMe())
        {
            Mouse.transform.position += vectorToTarget * movementSpeed * Time.deltaTime;
            ChangeColor(Color.red);
            rayColor = Color.green;
            wireDiscColor = Color.green;
        }
        else
        {
            ChangeColor(Color.white);
            rayColor = Color.red;
            wireDiscColor = Color.red;
        }

        Debug.DrawRay(Mouse.transform.position, vectorToTarget * rayLength, rayColor);
    }

    Vector3 GetTargetDirection()
    {
        return (Cheese.transform.position - Mouse.transform.position).normalized;
    }

    bool IsCloseToMe() 
    {
        float distance = (Cheese.transform.position - Mouse.transform.position).magnitude;
        return (distance <= wireDiscRadius) && (distance > distanceOffset);
    }

    void ChangeColor(Color color)
    {
        spriteRenderer.color = color;
    }
}
