using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class VectorsDistanceCalc : MonoBehaviour
{
    [Header("DRAW GIZMOS")]
    static public float staticWireDiscRadius = 75f;
    static public float staticRayLength = 15f;
    static public Color staticWireDiscColor = Color.red;
    static public Color staticRayColor = Color.red;
    static public Vector3 staticVectorToTarget;

    [Header("GAME OBJECTS")]
    [SerializeField] GameObject mouse;
    [SerializeField] GameObject cheese;
    [Space(10)]

    [Header("COMPONENT")]
    [SerializeField] SpriteRenderer spriteRenderer;
    [Space(10)]

    [Header("VECTOR")]
    [SerializeField] Vector3 vectorToTarget;
    [Space(10)]
    
    [Header("PARAMETERS")]
    [SerializeField] float movementSpeed = 100.0f;
    [SerializeField] float distanceOffset = 15.0f;
    [SerializeField] float wireDiscRadius = 75f;
    [SerializeField] float rayLength = 15.0f;
    [Space(10)]

    [Header("COLORS")]
    [SerializeField] Color mouseColor = Color.white;
    [SerializeField] Color wireDiscColor = Color.red;
    [SerializeField] Color rayColor = Color.red;
    
    void Awake()
    {
        mouse = GameObject.Find("Mouse");
        cheese = GameObject.Find("Cheese");
        spriteRenderer = mouse.GetComponent<SpriteRenderer>();

        if (mouse == null)
        {
            Debug.LogWarning("[Mouse] not found!");
        }

        if (cheese == null)
        {
            Debug.LogWarning("[Cheese] not found!");
        }

        if (spriteRenderer == null)
        {
            Debug.LogWarning("[Mouse Sprite Renderer] not found!");
        }
    }

    void Update()
    {
        // Display static variables in the inspector
        staticWireDiscRadius = wireDiscRadius;
        staticRayLength = rayLength;
        mouseColor = spriteRenderer.color; // Mouse sprite renderer color
        wireDiscColor = staticWireDiscColor;
        rayColor = staticRayColor;
        staticVectorToTarget = vectorToTarget;

        vectorToTarget = GetTargetDirection();

        if (IsCloseToMe())
        {
            mouse.transform.position += vectorToTarget * movementSpeed * Time.deltaTime;
            // Mouse.transform.position = Vector3.MoveTowards(Mouse.transform.position, Cheese.transform.position, movementSpeed * Time.deltaTime); // Alternative method with "MoveTowards"

            ChangeGizmosColor(Color.green);
            ChangeSpriteColor(Color.red);
        }
        else
        {
            ChangeGizmosColor(Color.red);
            ChangeSpriteColor(Color.white);
        }
    }

    // Compute the direction (return a normalized vector)
    Vector3 GetTargetDirection()
    {
        return (cheese.transform.position - mouse.transform.position).normalized; // equivalent of Vector3.Distance.normalized
    }

    // Compute the distance (return a boolean)
    bool IsCloseToMe() 
    {
        float distance = (cheese.transform.position - mouse.transform.position).magnitude; // equivalent of Vector3.magnitude

        return (distance <= staticWireDiscRadius) && (distance > distanceOffset);
    }

    //  Change ray and wire disc color
    void ChangeGizmosColor(Color color)
    {
        staticRayColor = color;
        staticWireDiscColor = color;
    }

    //  Change sprite color
    void ChangeSpriteColor(Color color)
    {
        spriteRenderer.color = color;
    }
}