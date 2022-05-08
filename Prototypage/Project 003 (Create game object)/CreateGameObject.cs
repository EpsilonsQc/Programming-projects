using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CreateGameObject : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        GameObject myEmptyGameObject = new GameObject(); // create an empty game object
        myEmptyGameObject.name = "My Empty Game Object"; // set name
        myEmptyGameObject.transform.SetParent(gameObject.transform, true); // set as child of the object attached to this script
        createPrimitives();
    }

    void createPrimitives()
    {
        GameObject myCube = GameObject.CreatePrimitive(PrimitiveType.Cube); // create a cube game object
        myCube.name = "My Cube"; // set name
        myCube.transform.position = new Vector3(-10, 0, 0); // set position
        myCube.transform.localScale = new Vector3(20, 1, 20); // set localScale (size)
        myCube.transform.rotation = Quaternion.Euler(30, 0, 0); // set rotation in the 3D world
        myCube.transform.SetParent(gameObject.transform, true); // set as child of the object attached to this script

        Debug.Log("Position: " + myCube.transform.position); // output the position of the object in the console
        Debug.Log("Local Position: " + myCube.transform.localPosition); // output the local position of the object in the console
    }
}