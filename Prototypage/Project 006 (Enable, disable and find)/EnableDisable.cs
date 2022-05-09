using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnableDisable : MonoBehaviour
{
    public GameObject myCube;  // Declare a variable of type GameObject
    private MeshRenderer mR; // Declare a variable of type MeshRenderer

    void Awake()
    {        
        // Assign "Cube" (GameObject) to my variable myCube
        myCube = GameObject.Find("Cube");

        // Assign the MeshRenderer component from myCube to my MeshRenderer variable mR
        mR = myCube.GetComponent<MeshRenderer>();
    }

    private void OnDisable() 
    {
        // Enable / disable the "Cube" OnDisable()
        mR.enabled = !mR.enabled;

        // Alternative method to do the same thing
        // mR.enabled = false;
    }

    private void OnEnable() 
    {
        // Enable / disable the "Cube" OnEnable()
        mR.enabled = !mR.enabled;

        // Alternative method to do the same thing
        // mR.enabled = true;
    }
}