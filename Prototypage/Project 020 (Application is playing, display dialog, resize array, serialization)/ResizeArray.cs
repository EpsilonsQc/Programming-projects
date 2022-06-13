using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor; // UnityEditor for "DisplayDialog"
using System;

public class ResizeArray : MonoBehaviour
{
    [Header("CUBES")]
    [SerializeField] private int cubes;
    [SerializeField] private GameObject [] myCubes;

    // OnValidate
    void OnValidate()
    {
        if(Application.isPlaying)
        {
            CubeDestruction();
            CubeCreation();
        }
    }

    void CubeDestruction()
    {
        for(int i = 0; i < myCubes.Length; i++)
        {
            Destroy(myCubes[i]);
        }
    }

    void CubeCreation()
    {
        if(cubes < 0)
        {
            cubes = 0;
            EditorUtility.DisplayDialog("WARNING", "You can't have less than 0 cube.", "OK"); // Title, Message, Button text
        }

        Array.Resize(ref myCubes, cubes);

        for(int i = 0; i < cubes ; i++)
        {
            GameObject cube = GameObject.CreatePrimitive(PrimitiveType.Cube);
            cube.transform.position = new Vector3(0, i, 0);
            cube.transform.localScale = new Vector3(cubes -i, 1, cubes - i);
            myCubes[i] = cube;
        }
    }
}