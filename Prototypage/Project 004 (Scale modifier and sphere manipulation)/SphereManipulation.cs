using System.Collections; 
using System.Collections.Generic;
using UnityEngine;

public class SphereManipulation : MonoBehaviour
{

    [SerializeField] private int numberOfSphere = 10;
    [SerializeField] private GameObject randomSizeSphere;

    private int sphereCount = 0;
    
    // Start is called before the first frame update
    void Start()
    {
        // For loop creating a column of spheres
        for (float i = 0; i < numberOfSphere; i++)
        {
            ++sphereCount; // increment sphere count
            GameObject sphere = GameObject.CreatePrimitive(PrimitiveType.Sphere);
            sphere.name = "Sphere" + sphereCount; // set name of each spheres
            sphere.transform.SetParent(gameObject.transform, false); // set sphere as a child of the gameObject attached to this script
            sphere.transform.localScale = new Vector3(i, i , i); // localScale increment with each for loop
            sphere.transform.position = new Vector3(0, i * i / 2, 0); // position change with each for loop
        }

            // A random Size Sphere
            randomSizeSphere = GameObject.CreatePrimitive(PrimitiveType.Sphere);
            randomSizeSphere.name = "Random Size Sphere"; // set name
            randomSizeSphere.transform.SetParent(gameObject.transform, false); // set sphere as a child of the gameObject attached to this script
            randomSizeSphere.transform.localScale = new Vector3(1, 1 , 1); // localScal
            randomSizeSphere.transform.position = new Vector3(30 , 0, 0); // position  
    }

    private void OnDisable()
    {
        randomSizeSphere.AddComponent<Rigidbody>();

        // Add component from the class/script <ScaleModifier>
        ScaleModifier ScaleModifierObject = randomSizeSphere.AddComponent<ScaleModifier>(); // Add component

        // Get component from the class/script <ScaleModifier>
        // ScaleModifier ScaleModifierObject = mySphere.GetComponent<ScaleModifier>(); // Get component

        ScaleModifierObject.setScaleOnDisable = Random.Range(1, 10); // assign a value to a variable from <ScaleModifier> script
        ScaleModifierObject.ChangeScale(); // use a fonction from <ScaleModifier> script
    }

    // Update is called once per frame
    void Update()
    {
        int randomInt = Random.Range(1, 15);
        randomSizeSphere.transform.localScale = new Vector3(randomInt, randomInt, randomInt);

        Debug.Log("I am a random float: " + Random.Range(0,2)); // random float (exclusive)
        Debug.Log("I am a random float: " + Random.Range(0f,1f)); // random float (inclusive)
    }
}