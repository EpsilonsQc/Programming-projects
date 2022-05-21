using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CarMovement : MonoBehaviour
{
    private GameObject endPoint; // end point for caravan move

    // Car parameters
    [HideInInspector] static public bool carMove = false; // enable-disable car movement
    private int maxSpeed = 500; // car maximum movement speed
    

    void Awake()
    {
        endPoint = GameObject.Find("World Generator/car/end_point");
    }

    // Update is called once per frame
    void Update()
    {
        MoveCar();
    }
    
    // Move car
    void MoveCar()
    {
        if (carMove == true)
        {
            transform.position = Vector3.MoveTowards(transform.position, endPoint.transform.position, maxSpeed * Time.deltaTime);
        }
    }

    // Enable-disable car movement
    static public void EnableCarMovement()
    {
        if (carMove == true)
        {
            carMove = false;
        }
        else if (carMove == false)
        {
            carMove = true;
        }
    }
}