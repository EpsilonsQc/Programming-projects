using System.Collections; 
using System.Collections.Generic;
using UnityEngine;

public class FindGameObject : MonoBehaviour
{
    // Declare variables of type GameObject
    public GameObject myCube; 
    public GameObject mySphere;
    public GameObject myCylinder;
    public GameObject[] MyObjectsArray;

    void Awake()
    {
        // Find a GameObject by name
        myCube = GameObject.Find("Cube");

        // Find a GameObject by name within a parent/child tree
        mySphere = GameObject.Find("All my objects/Find by name/Sphere");

        // Find a GameObject by tag
        // Tag are defined and assigned for each GameObject individually in the inspector
        myCylinder = GameObject.FindWithTag("CylinderTag");

        // Find multiples GameObjects with the same "Tag"
        // Tag are defined and assigned for each GameObject individually in the inspector
        MyObjectsArray = GameObject.FindGameObjectsWithTag ("GameObjectTag");
    }
}
