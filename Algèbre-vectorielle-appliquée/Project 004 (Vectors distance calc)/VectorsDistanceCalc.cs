using System.Collections; 
using System.Collections.Generic;
using UnityEngine;

public class VectorsDistanceCalc : MonoBehaviour
{
    [Header("SPRITES")]
    [SerializeField] private GameObject Mouse;
    [SerializeField] private GameObject Cheese;
    [Space(15)]
    
    [Header("PARAMETERS")]
    [SerializeField] private float SpeedMax = 100.0f;
    [SerializeField] private float DistanceMax = 15.0f;

    void Awake()
    {
        Mouse = GameObject.Find("Mouse");
        Cheese = GameObject.Find("Cheese");
    }

    // Update is called once per frame
    void Update()
    {
        Debug.Log("Name: " + Mouse.gameObject.name + " Position: " + Mouse.gameObject.transform.position);
        Debug.Log("Name: " + Cheese.gameObject.name + " Position: " + Cheese.gameObject.transform.position);
        
        Vector2 DistanceVector = VectorGeometric(Mouse.transform.position, Cheese.transform.position);

        if (DistanceMax < vectorDistance(DistanceVector))
        {
            Mouse.transform.position = Vector3.MoveTowards(Mouse.transform.position, Cheese.transform.position, SpeedMax * Time.deltaTime);
            // Mouse.transform.position += (Vector3)DistanceVector * SpeedMax * Time.deltaTime;
        }
    }

    private Vector2 VectorGeometric(Vector2 startPos, Vector2 endPos)
    {
        return endPos - startPos;
    }

    private float vectorDistance (Vector2 myVector)
    {
        float distance = Mathf.Sqrt(myVector.x * myVector.x + myVector.y * myVector.y); // equivalent of myVector.magnitude
        // float distance = myVector.magnitude;

        return distance;
    }

    private float vectorDistance (Vector2 coord_1, Vector2 coord_2)
    {
        float distance = Mathf.Sqrt( (coord_2.x - coord_1.x) * (coord_2.x - coord_1.x) + (coord_2.y - coord_1.y) * (coord_2.y - coord_2.y) ); // equivalent of myVector.magnitude
        // float distance = Mathf.Sqrt(Mathf.Pow(vec.x, 2) + Mathf.Pow(vec.y, 2)); // equivalent of myVector.magnitude
        // float distance = myVector.magnitude;

        return distance;
    }
}
