using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TowerGenerator : MonoBehaviour
{
    // Private variables [hidden]
    int towerCount = 0;
    int pyramidCount = 0;

    // Serialized variables [available in the inspector]
    [SerializeField] private Vector3 defaultPosition = new Vector3(0, 0, 0); // coordonnée x, y, z de mes tours et pyramides
    [SerializeField] private bool medievalMode = false; // active/désactive le mode "chateau" des tours
    [SerializeField] private bool pyramid = false; // détermine si on génère une tour ou une pyramide
    [SerializeField] private int width = 10; // largeur des tours [width]
    [SerializeField] private int floorsQuantity = 25; // nombre d'étage de tour [floors]
    [SerializeField] private float cubeSize = 1.0f; // taille des cubes [size]
    [SerializeField] private bool randomizeCubeSize = false; // active/désactive la variation de la taille des cubes [random size]
    [SerializeField] private float cubeSizeMin = 1.00f; // taille minimal pour random size
    [SerializeField] private float cubeSizeMax = 1.50f; // taille maximal pour random size

    // Game Objects (tower, pyramid, floors, central cube, cubes)
    GameObject Tower;
    GameObject Pyramid;
    GameObject Floors;
    GameObject CentralCube;
    GameObject Cubes;

    // Execute on script/component deactivation
    void OnDisable()
    {
        if (pyramid == false)
        {
            CreateTowers();
        }
        else if (pyramid == true)
        {
            CreatePyramid();
        }
    }

    // Tower generation
    void CreateTowers()
    {   
        int towerFloorsCount = 0;

        bool lastFloor = false;

        int countSideA = 1;
        int countSideB = 1;
        int countSideC = 1;
        int countSideD = 1;

        // Create an empty game object called "Tower #"
        Tower = new GameObject();
        ++towerCount;
        Tower.name = "Tower " + towerCount;
        Tower.transform.position = defaultPosition;

        for (int i = 0; i < floorsQuantity; i++)
        {      
            // Create an empty game object called "Floors #"  
            Floors = new GameObject();
            ++towerFloorsCount;
            Floors.name = "Floors " + towerFloorsCount;
            Floors.transform.SetParent(Tower.transform, false);
            Floors.transform.position = defaultPosition;

            // If first floor, create a central cube 
            if (towerFloorsCount == 1)
            {
            CentralCube = GameObject.CreatePrimitive(PrimitiveType.Cube);
            CentralCube.name = "Cube Central";
            CentralCube.transform.SetParent(Floors.transform, false);
            CentralCube.transform.localPosition = new Vector3(width / 2, 0, width / 2);
            }

                // Print side A
                for (int a = 0; a < width; ++a)
                {
                        Cubes = GameObject.CreatePrimitive(PrimitiveType.Cube);
                        Cubes.name = "Cube " + countSideA + " (Side A)";
                        ++countSideA;
                        SetCubeSize();
                        Cubes.transform.SetParent(Floors.transform, false);
                        if (towerFloorsCount == 1 || towerFloorsCount != floorsQuantity)
                        {
                            Cubes.transform.localPosition = new Vector3(a, i, 0);
                        }
                        else if (lastFloor == true && medievalMode == true)
                        {
                            Cubes.transform.localPosition = new Vector3(a, i, 0);
                            lastFloor = false;
                        }
                        else if (towerFloorsCount == floorsQuantity)
                        {
                            lastFloor = true;
                        }
                }

                // Print side B
                for (int b = 0; b < width; ++b)
                {
                        Cubes = GameObject.CreatePrimitive(PrimitiveType.Cube);
                        Cubes.name = "Cube " + countSideB + " (Side B)";
                        ++countSideB;
                        SetCubeSize();
                        Cubes.transform.SetParent(Floors.transform, false);
                        if (towerFloorsCount == 1 || towerFloorsCount != floorsQuantity)
                        {
                            Cubes.transform.localPosition = new Vector3(width, i, b);
                        }
                        else if (lastFloor == true && medievalMode == true)
                        {
                            Cubes.transform.localPosition = new Vector3(width, i, b);
                            lastFloor = false;
                        }
                        else if (towerFloorsCount == floorsQuantity)
                        {
                            lastFloor = true;
                        }
                }

                // Print side C
                for (int c = 0; c < width; ++c)
                {
                        Cubes = GameObject.CreatePrimitive(PrimitiveType.Cube);
                        Cubes.name = "Cube " + countSideC + " (Side C)";
                        ++countSideC;
                        SetCubeSize();
                        Cubes.transform.SetParent(Floors.transform, false);
                        if (towerFloorsCount == 1 || towerFloorsCount != floorsQuantity)
                        {
                            Cubes.transform.localPosition = new Vector3(c + 1, i, width);
                        }
                        else if (lastFloor == true && medievalMode == true)
                        {
                            Cubes.transform.localPosition = new Vector3(c + 1, i, width);
                            lastFloor = false;
                        }
                        else if (towerFloorsCount == floorsQuantity)
                        {
                            lastFloor = true;
                        }
                }

                // Print side D
                for (int d = 0; d < width; ++d)
                {
                        Cubes = GameObject.CreatePrimitive(PrimitiveType.Cube);
                        Cubes.name = "Cube " + countSideD + " (Side D)";
                        ++countSideD;
                        SetCubeSize();
                        Cubes.transform.SetParent(Floors.transform, false);
                        if (towerFloorsCount == 1 || towerFloorsCount != floorsQuantity)
                        {
                            Cubes.transform.localPosition = new Vector3(0, i, d + 1);
                        }
                        else if (lastFloor == true && medievalMode == true)
                        {
                            Cubes.transform.localPosition = new Vector3(0, i, d + 1);
                            lastFloor = false;
                        }
                        else if (towerFloorsCount == floorsQuantity)
                        {
                            lastFloor = true;
                        }
                }
        }
    }

    // Pyramid generation
    void CreatePyramid()
    {
        int pyramidFloorsCount = 0;
        int incrementForEachFloors = 0;
        int pyramideWidth = width;

        int countSideA = 1;
        int countSideB = 1;
        int countSideC = 1;
        int countSideD = 1;

        // Create an empty game object called "Tower #"
        Pyramid = new GameObject();
        ++pyramidCount;
        Pyramid.name = "Pyramid " + pyramidCount;
        Pyramid.transform.position = defaultPosition;

        for (int i = 0; i < width / 2; i++) // number of floors iteration [width / 2 = top of pyramid]
        {     
            ++incrementForEachFloors; // +1 on X or Z axis (depend on side) for each floors [used to create the pyramid form]
            pyramideWidth -= 2; // for each floor, remove two cube on every sides [used to create the pyramid form]

            // Create empty game objects called "Floors #"
            Floors = new GameObject();
            ++pyramidFloorsCount;
            Floors.name = "Floors " + pyramidFloorsCount;
            Floors.transform.SetParent(Pyramid.transform, false);
            Floors.transform.position = defaultPosition;

            // If first floor, create a central cube 
            if (pyramidFloorsCount == 1)
            {
            CentralCube = GameObject.CreatePrimitive(PrimitiveType.Cube);
            CentralCube.name = "Cube Central";
            CentralCube.transform.SetParent(Floors.transform, false);
            CentralCube.transform.localPosition = new Vector3(width / 2, 0, width / 2);
            }

                // Print side A
                for (int a = 0; a < pyramideWidth; a++)
                {
                    Cubes = GameObject.CreatePrimitive(PrimitiveType.Cube);
                    Cubes.name = "Cube " + countSideA + " (Side A)";
                    ++countSideA;
                    SetCubeSize();
                    Cubes.transform.SetParent(Floors.transform, false);
                    Cubes.transform.localPosition = new Vector3(a + incrementForEachFloors, i, 1 + incrementForEachFloors);;
                }

                // Print side B
                for (int b = 0; b < pyramideWidth; b++)
                {
                    Cubes = GameObject.CreatePrimitive(PrimitiveType.Cube);
                    Cubes.name = "Cube " + countSideB + " (Side B)";
                    ++countSideB;
                    SetCubeSize();
                    Cubes.transform.SetParent(Floors.transform, false);
                    Cubes.transform.localPosition = new Vector3(width - incrementForEachFloors, i, b + incrementForEachFloors + 1);
                }

                // Print side C
                for (int c = 0; c < pyramideWidth; c++)
                {
                    Cubes = GameObject.CreatePrimitive(PrimitiveType.Cube);
                    Cubes.name = "Cube " + countSideC + " (Side C)";
                    ++countSideC;
                    SetCubeSize();
                    Cubes.transform.SetParent(Floors.transform, false);
                    Cubes.transform.localPosition = new Vector3(c + incrementForEachFloors, i, width - incrementForEachFloors);
                }

                // Print side D
                for (int d = 0; d < pyramideWidth; d++)
                {
                    Cubes = GameObject.CreatePrimitive(PrimitiveType.Cube);
                    Cubes.name = "Cube " + countSideD + " (Side D)";
                    ++countSideD;
                    SetCubeSize();
                    Cubes.transform.SetParent(Floors.transform, false);
                    Cubes.transform.localPosition = new Vector3(incrementForEachFloors, i, d + incrementForEachFloors + 1);
                }
        }
    }

    // Change size of cube [generic/default and randomized]
    void SetCubeSize()
    {
        if (randomizeCubeSize == false)
        {
            // Set default cube size
            Cubes.transform.localScale = new Vector3(cubeSize, cubeSize, cubeSize);
        }
        else if (randomizeCubeSize == true)
        {
            // Randomize cube size
            Cubes.transform.localScale = new Vector3(Random.Range(cubeSizeMin, cubeSizeMax), Random.Range(cubeSizeMin, cubeSizeMax), Random.Range(cubeSizeMin, cubeSizeMax));
        }
    }
}