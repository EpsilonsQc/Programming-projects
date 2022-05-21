using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class WorldGenerator : MonoBehaviour
{
    // Ground
    private GameObject ground; // flat ground
    private MeshRenderer groundMR; // flat ground mesh renderer
    private int groundHeightVariation = 100; // default heigth variation for the ground

    // Car
    private GameObject car; // caravan
    private GameObject endPoint; // end point for caravan move

    // Car parameters
    private bool carActivated = false;
    private bool CarMovementScriptAdded = false;

    // Car parts (gameObject)
    private GameObject front_left_wheel;
    private GameObject front_right_wheel;
    private GameObject rear_left_wheel;
    private GameObject rear_right_wheel;
    private GameObject van_body;
    private GameObject van_canvas;

    // Car parts (Mesh Renderer and Canvas)
    private MeshRenderer front_left_wheelMR;
    private MeshRenderer front_right_wheelMR;
    private MeshRenderer rear_left_wheelMR;
    private MeshRenderer rear_right_wheelMR;
    private MeshRenderer van_bodyMR;
    private Canvas van_canvasCanvas;

    // World generator parameters
    private int rockAmount = 0;
    private int treeAmount = 0;
    private float worldSize = 0f;
    private bool worldGenerated = false;

    // World assets
    private GameObject rock_01;
    private GameObject rock_02;
    private GameObject tree_cactus_01;
    private GameObject tree_cactus_02;
    private GameObject tree_palm;
    private GameObject tree_plant;

    // Special assets (rare)
    private GameObject bone_01;
    private GameObject bone_02;
    private GameObject well_01;
    private GameObject well_02;


    void Awake()
    {
        ground = GameObject.Find("World Generator/ground/flat_ground");
        groundMR = ground.GetComponent<MeshRenderer>();

        car = GameObject.Find("World Generator/car/caravan");
        endPoint = GameObject.Find("World Generator/car/end_point");

        front_left_wheel = GameObject.Find("World Generator/car/caravan/front_left_wheel");
        front_right_wheel = GameObject.Find("World Generator/car/caravan/front_right_wheel");
        rear_left_wheel = GameObject.Find("World Generator/car/caravan/rear_left_wheel");
        rear_right_wheel = GameObject.Find("World Generator/car/caravan/rear_right_wheel");
        van_body = GameObject.Find("World Generator/car/caravan/van_body");
        van_canvas = GameObject.Find("World Generator/car/caravan/van_canvas");

        rock_01 = GameObject.Find("World Generator/world_assets/rock_01");
        rock_02 = GameObject.Find("World Generator/world_assets/rock_02");
        tree_cactus_01 = GameObject.Find("World Generator/world_assets/tree_cactus_01");
        tree_cactus_02 = GameObject.Find("World Generator/world_assets/tree_cactus_02");
        tree_palm = GameObject.Find("World Generator/world_assets/tree_palm");
        tree_plant = GameObject.Find("World Generator/world_assets/tree_plant");

        bone_01 = GameObject.Find("World Generator/world_assets/bone_01");
        bone_02 = GameObject.Find("World Generator/world_assets/bone_02");
        well_01 = GameObject.Find("World Generator/world_assets/well_01");
        well_02 = GameObject.Find("World Generator/world_assets/well_02");

        front_left_wheelMR = front_left_wheel.GetComponent<MeshRenderer>();
        front_right_wheelMR = front_right_wheel.GetComponent<MeshRenderer>();
        rear_left_wheelMR = rear_left_wheel.GetComponent<MeshRenderer>();
        rear_right_wheelMR = rear_right_wheel.GetComponent<MeshRenderer>();
        van_bodyMR = van_body.GetComponent<MeshRenderer>();
        van_canvasCanvas = van_canvas.GetComponent<Canvas>();

        tree_cactus_01.AddComponent<WindSimulation>();
        tree_cactus_02.AddComponent<WindSimulation>();
        tree_palm.AddComponent<WindSimulation>();
        tree_plant.AddComponent<WindSimulation>();
    }

    // Generate world
    public void GenerateWorld()
    {
        // Clear previous world generation (destroy all "clones")
        if (worldGenerated == true)
        {
            GameObject clone = GameObject.FindWithTag ("clone");
            Destroy(clone);
        }

        // Create parent for instanciated objects
        GameObject instanciated_objects = new GameObject(); 
        instanciated_objects.name = "instanciated_objects";
        instanciated_objects.transform.SetParent(gameObject.transform, true);
        instanciated_objects.tag = "clone"; // add clone tag to parent of all instanciated objects

        GameObject instanciated_rocks = new GameObject(); 
        instanciated_rocks.name = "rocks";
        instanciated_rocks.transform.SetParent(instanciated_objects.transform, true);

        GameObject instanciated_trees = new GameObject(); 
        instanciated_trees.name = "trees";
        instanciated_trees.transform.SetParent(instanciated_objects.transform, true);

        GameObject instanciated_specials = new GameObject(); 
        instanciated_specials.name = "specials";
        instanciated_specials.transform.SetParent(instanciated_objects.transform, true);

        if (carActivated == true)
        {
            // Hide the car on screen (disable all MeshRenderer and Canvas)
            front_left_wheelMR.enabled = false;
            front_right_wheelMR.enabled = false;
            rear_left_wheelMR.enabled = false;
            rear_right_wheelMR.enabled = false;
            van_bodyMR.enabled = false;
            van_canvasCanvas.enabled = false;

            CarMovement.carMove = false;
            car.transform.position = new Vector3(0, 0, -worldSize * 4.5f); // Reset car position at beginning of the world
        }

        // Add ground
         groundMR.enabled = true;
         ground.transform.localScale = new Vector3(worldSize, groundHeightVariation, worldSize);

         // Road offset
         float roadOffset = worldSize / 2;

        // Random scale parameters for instenciations
        int minScale = 20;
        int maxScale = 60;

        // Add rocks
        if(rockAmount != 0)
        {
            // ROCK 01
            for (int i = 0; i <= rockAmount / 4; ++i)
            {
                // Left side of the road
                Instantiate(rock_01, new Vector3(Random.Range(-worldSize * 5, -roadOffset), 0, Random.Range(-worldSize * 5, worldSize * 5)), Quaternion.Euler(Random.Range(-5, 5), Random.Range(-2160, 2160), Random.Range(-5, 5)), transform.parent = instanciated_rocks.transform);
                rock_01.transform.localScale = new Vector3(Random.Range(minScale, maxScale),Random.Range(minScale, maxScale),Random.Range(minScale, maxScale));

                // Right side of the road
                Instantiate(rock_01, new Vector3(Random.Range(worldSize * 5, roadOffset), 0, Random.Range(-worldSize * 5, worldSize * 5)), Quaternion.Euler(Random.Range(-5, 5), Random.Range(-2160, 2160), Random.Range(-5, 5)), transform.parent = instanciated_rocks.transform);
                rock_01.transform.localScale = new Vector3(Random.Range(minScale, maxScale),Random.Range(minScale, maxScale),Random.Range(minScale, maxScale));
            }

            // ROCK 02
            for (int i = 0; i <= rockAmount / 4; ++i)
            {
                // Left side of the road
                Instantiate(rock_02, new Vector3(Random.Range(-worldSize * 5, -roadOffset), 0, Random.Range(-worldSize * 5, worldSize * 5)), Quaternion.Euler(Random.Range(-5, 5), Random.Range(-2160, 2160), Random.Range(-5, 5)), transform.parent = instanciated_rocks.transform);
                rock_02.transform.localScale = new Vector3(Random.Range(minScale, maxScale),Random.Range(minScale, maxScale),Random.Range(minScale, maxScale));

                // Right side of the road
                Instantiate(rock_02, new Vector3(Random.Range(worldSize * 5, roadOffset), 0, Random.Range(-worldSize * 5, worldSize * 5)), Quaternion.Euler(Random.Range(-5, 5), Random.Range(-2160, 2160), Random.Range(-5, 5)), transform.parent = instanciated_rocks.transform);
                rock_02.transform.localScale = new Vector3(Random.Range(minScale, maxScale),Random.Range(minScale, maxScale),Random.Range(minScale, maxScale));
            }
        }

        // Add trees
        if(treeAmount != 0)
        {

            // TREE CACTUS 01
            for (int i = 0; i <= treeAmount / 8; ++i)
            {
                // Left side of the road
                Instantiate(tree_cactus_01, new Vector3(Random.Range(-worldSize * 5, -roadOffset), 0, Random.Range(-worldSize * 5, worldSize * 5)), Quaternion.Euler(Random.Range(-5, 5), Random.Range(-2160, 2160), Random.Range(-5, 5)), transform.parent = instanciated_trees.transform);
                tree_cactus_01.transform.localScale = new Vector3(Random.Range(minScale, maxScale),Random.Range(minScale, maxScale),Random.Range(minScale, maxScale));

                // Right side of the road
                Instantiate(tree_cactus_01, new Vector3(Random.Range(worldSize * 5, roadOffset), 0, Random.Range(-worldSize * 5, worldSize * 5)), Quaternion.Euler(Random.Range(-5, 5), Random.Range(-2160, 2160), Random.Range(-5, 5)), transform.parent = instanciated_trees.transform);
                tree_cactus_01.transform.localScale = new Vector3(Random.Range(minScale, maxScale),Random.Range(minScale, maxScale),Random.Range(minScale, maxScale));
            }

            // TREE CACTUS 02
            for (int i = 0; i <= treeAmount / 8; ++i)
            {
                // Left side of the road
                Instantiate(tree_cactus_02, new Vector3(Random.Range(-worldSize * 5, -roadOffset), 0, Random.Range(-worldSize * 5, worldSize * 5)), Quaternion.Euler(Random.Range(-5, 5), Random.Range(-2160, 2160), Random.Range(-5, 5)), transform.parent = instanciated_trees.transform);
                tree_cactus_02.transform.localScale = new Vector3(Random.Range(minScale, maxScale),Random.Range(minScale, maxScale),Random.Range(minScale, maxScale));

                // Right side of the road
                Instantiate(tree_cactus_02, new Vector3(Random.Range(worldSize * 5, roadOffset), 0, Random.Range(-worldSize * 5, worldSize * 5)), Quaternion.Euler(Random.Range(-5, 5), Random.Range(-2160, 2160), Random.Range(-5, 5)), transform.parent = instanciated_trees.transform);
                tree_cactus_02.transform.localScale = new Vector3(Random.Range(minScale, maxScale),Random.Range(minScale, maxScale),Random.Range(minScale, maxScale));
            }

            // PALM TREE
            for (int i = 0; i <= treeAmount / 8; ++i)
            {
                // Left side of the road
                Instantiate(tree_palm, new Vector3(Random.Range(-worldSize * 5, -roadOffset), 0, Random.Range(-worldSize * 5, worldSize * 5)), Quaternion.Euler(Random.Range(-5, 5), Random.Range(-2160, 2160), Random.Range(-5, 5)), transform.parent = instanciated_trees.transform);
                tree_palm.transform.localScale = new Vector3(Random.Range(minScale, maxScale),Random.Range(minScale, maxScale),Random.Range(minScale, maxScale));

                // Right side of the road
                Instantiate(tree_palm, new Vector3(Random.Range(worldSize * 5, roadOffset), 0, Random.Range(-worldSize * 5, worldSize * 5)), Quaternion.Euler(Random.Range(-5, 5), Random.Range(-2160, 2160), Random.Range(-5, 5)), transform.parent = instanciated_trees.transform);
                tree_palm.transform.localScale = new Vector3(Random.Range(minScale, maxScale),Random.Range(minScale, maxScale),Random.Range(minScale, maxScale));
            }

            // TREE PLANT
            for (int i = 0; i <= treeAmount / 8; ++i)
            {
                // Left side of the road
                Instantiate(tree_plant, new Vector3(Random.Range(-worldSize * 5, -roadOffset), 0, Random.Range(-worldSize * 5, worldSize * 5)), Quaternion.Euler(Random.Range(-5, 5), Random.Range(-2160, 2160), Random.Range(-5, 5)), transform.parent = instanciated_trees.transform);
                tree_plant.transform.localScale = new Vector3(Random.Range(minScale, maxScale),Random.Range(minScale, maxScale),Random.Range(minScale, maxScale));

                // Right side of the road
                Instantiate(tree_plant, new Vector3(Random.Range(worldSize * 5, roadOffset), 0, Random.Range(-worldSize * 5, worldSize * 5)), Quaternion.Euler(Random.Range(-5, 5), Random.Range(-2160, 2160), Random.Range(-5, 5)), transform.parent = instanciated_trees.transform);
                tree_plant.transform.localScale = new Vector3(Random.Range(minScale, maxScale),Random.Range(minScale, maxScale),Random.Range(minScale, maxScale));
            }
        }

            // SPECIAL FACULTATIVE PROCEDURAL ITEMS - ESTHETIC ONLY. 
            // BONE 01
            for (int i = 0; i <= 1; ++i)
            {
                // Left side of the road
                Instantiate(bone_01, new Vector3(Random.Range(-worldSize * 5, -roadOffset), 0, Random.Range(-worldSize * 5, worldSize * 5)), Quaternion.Euler(Random.Range(-5, 5), Random.Range(-2160, 2160), Random.Range(-5, 5)), transform.parent = instanciated_specials.transform);
                bone_01.transform.localScale = new Vector3(Random.Range(minScale, maxScale),Random.Range(minScale, maxScale),Random.Range(minScale, maxScale));

                // Right side of the road
                Instantiate(bone_01, new Vector3(Random.Range(worldSize * 5, roadOffset), 0, Random.Range(-worldSize * 5, worldSize * 5)), Quaternion.Euler(Random.Range(-5, 5), Random.Range(-2160, 2160), Random.Range(-5, 5)), transform.parent = instanciated_specials.transform);
                bone_01.transform.localScale = new Vector3(Random.Range(minScale, maxScale),Random.Range(minScale, maxScale),Random.Range(minScale, maxScale));
            }

            // BONE 02
            for (int i = 0; i <= 1; ++i)
            {
                // Left side of the road
                Instantiate(bone_02, new Vector3(Random.Range(-worldSize * 5, -roadOffset), 0, Random.Range(-worldSize * 5, worldSize * 5)), Quaternion.Euler(Random.Range(-5, 5), Random.Range(-2160, 2160), Random.Range(-5, 5)), transform.parent = instanciated_specials.transform);
                bone_02.transform.localScale = new Vector3(Random.Range(minScale, maxScale),Random.Range(minScale, maxScale),Random.Range(minScale, maxScale));

                // Right side of the road
                Instantiate(bone_02, new Vector3(Random.Range(worldSize * 5, roadOffset), 0, Random.Range(-worldSize * 5, worldSize * 5)), Quaternion.Euler(Random.Range(-5, 5), Random.Range(-2160, 2160), Random.Range(-5, 5)), transform.parent = instanciated_specials.transform);
                bone_02.transform.localScale = new Vector3(Random.Range(minScale, maxScale),Random.Range(minScale, maxScale),Random.Range(minScale, maxScale));
            }

            // WELL 01
            for (int i = 0; i <= 0; i++)
            {
                // Left side of the road
                Instantiate(well_01, new Vector3(Random.Range(-worldSize * 5, -roadOffset), 0, Random.Range(-worldSize * 5, worldSize * 5)), Quaternion.Euler(Random.Range(-5, 5), Random.Range(-2160, 2160), Random.Range(-5, 5)), transform.parent = instanciated_specials.transform);
                well_01.transform.localScale = new Vector3(Random.Range(minScale, maxScale),Random.Range(minScale, maxScale),Random.Range(minScale, maxScale));
            }

            // WELL 02
            for (int i = 0; i <= 0; i++)
            {
                // Right side of the road
                Instantiate(well_02, new Vector3(Random.Range(worldSize * 5, roadOffset), 0, Random.Range(-worldSize * 5, worldSize * 5)), Quaternion.Euler(Random.Range(-5, 5), Random.Range(-2160, 2160), Random.Range(-5, 5)), transform.parent = instanciated_specials.transform);
                well_02.transform.localScale = new Vector3(Random.Range(minScale, maxScale),Random.Range(minScale, maxScale),Random.Range(minScale, maxScale));
            }

        worldGenerated = true;
    }

    // Receive amount of ROCKS from input field
    public void RockAmountInput(string rockAmountText)
    {
        rockAmount = int.Parse(rockAmountText);
    }
    // Receive amount of TREES from input field
    public void TreeAmountInput(string treeAmountText)
    {
        treeAmount = int.Parse(treeAmountText);
    }

    // Receive WORLD SIZE from input field
    public void WorldSizeInput(string worldSizeText)
    {
        worldSize = int.Parse(worldSizeText);
    }

    // Add car to world
    public void AddCar()
    {
        carActivated = true;
        CarMovement.carMove = false;

        // Set car start location on the world
        car.transform.position = new Vector3(0, 1, -worldSize * 4.25f);

        // Set "move car" end point position
        endPoint.transform.position = new Vector3(0, 0, worldSize * 4.25f);

        // Show the car on screen (enable all MeshRenderer and Canvas)
        front_left_wheelMR.enabled = true;
        front_right_wheelMR.enabled = true;
        rear_left_wheelMR.enabled = true;
        rear_right_wheelMR.enabled = true;
        van_bodyMR.enabled = true;
        van_canvasCanvas.enabled = true;
    }

    public void AddCarMovementScript()
    {
        if (CarMovementScriptAdded == false) 
            {
                car.AddComponent<CarMovement>();
                CarMovementScriptAdded = true;
                CarMovement.carMove = true;
            }
        else if (CarMovementScriptAdded == true)
        {
            CarMovement.EnableCarMovement();
        }
    }
}