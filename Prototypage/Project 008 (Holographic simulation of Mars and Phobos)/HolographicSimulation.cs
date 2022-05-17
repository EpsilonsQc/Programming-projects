using System.Collections; 
using System.Collections.Generic;
using UnityEngine;

public class HolographicSimulation : MonoBehaviour
{  
    [Header("SPACE GRID")]
    [SerializeField] private bool SpaceGrid = true;
    [SerializeField] private Color SpaceGridColor = new Color (0f, 0.93097f, 1f, 1f); // Cyan blue
    [SerializeField] [Range(1, 600)] private int SpaceGridSize = 300;
    [SerializeField] [Range(5, 50)] private int SpaceGridSpacing = 10;
    [SerializeField] [Range(-250, 250)] private int SpaceGridHeight = 0;
    [Space(15)]

    [Header("SUN")]
    [SerializeField] private bool Sun = true;
    [SerializeField] private Color SunColor = new Color (1f, 0.5555555f, 0f, 1f); // Orange
    [SerializeField] [Range(10, 25)] private float SunSize = 10.0f;
    private Vector3 sunPosition = new Vector3(0, 0, 0);
    [Space(15)]

    [Header("MARS")]
    [SerializeField] private bool Mars = true;
    [SerializeField] private Color MarsColor = new Color (0.8823529f, 0f, 0f, 1); // Red
    [SerializeField] [Range(5, 10)] private float MarsSize = 5.0f;
    [SerializeField] private Vector3 MarsOrbitOffset = new Vector3(25, 0, 25); // Mars orbit offset parameter
    [SerializeField] private Vector3 MarsEclipticOrbitParam = new Vector3(100, 0, 50); // Mars ecliptic orbit size parameter
    [SerializeField] private bool MarsClockwiseOrbit = true;
    private Vector3 marsPosition = new Vector3(0, 0, 0);
    [Space(15)]

    [Header("PHOBOS")]
    [SerializeField] private bool Phobos = true;
    [SerializeField] private Color PhobosColor = new Color (0.01960784f, 1f, 0f, 1f); // Green
    [SerializeField] [Range(1, 5)] private float PhobosSize = 1.0f;
    [SerializeField] [Range (5, 20)] private int PhobosSpeed = 5;
    [SerializeField] [Range (5, 20)] private int PhobosOrbitDistance = 5;
    [SerializeField] private bool PhobosClockwiseOrbit = true;
    private Vector3 phobosPosition = new Vector3(0, 0, 0);

    // Update is called once per frame
    void Update()
    {
        displaySpaceGrid();
        displaySun();
        displayMars();
        displayPhobos();
    }

    // Space grid
    void displaySpaceGrid()
    {
        if (SpaceGrid == true)
        {
            int linesCounter = SpaceGridSize / SpaceGridSpacing;
            int halfGridSize = SpaceGridSize / 2;
            int spacingCounter = 0;
            int axisCoordinate = 0;
            axisCoordinate = axisCoordinate - halfGridSize;

            for (int i = 0; i <= linesCounter; i++)
            {
                // X-Axis line
                Debug.DrawLine(new Vector3(axisCoordinate, SpaceGridHeight, -halfGridSize), new Vector3(axisCoordinate, SpaceGridHeight, halfGridSize), SpaceGridColor, 0.0f);

                // Z-Axis line
                Debug.DrawLine(new Vector3(-halfGridSize, SpaceGridHeight, axisCoordinate), new Vector3(halfGridSize, SpaceGridHeight, axisCoordinate), SpaceGridColor, 0.0f);
                
                spacingCounter = spacingCounter + SpaceGridSpacing;
                axisCoordinate = spacingCounter - halfGridSize;
            }
        }
    }

    // Sun
    void displaySun()
    {
        if (Sun == true)
        {
            // Sun DrawLine
            Debug.DrawLine(Random.onUnitSphere * SunSize + sunPosition, Random.onUnitSphere * SunSize + sunPosition, SunColor, 1.0f);
        }
    }

    // Mars
    void displayMars()
    {
        if (Mars == true)
        {

            if (MarsClockwiseOrbit == true) // Clockwise rotation
            {
                marsPosition.x = MarsOrbitOffset.x + Mathf.Sin(Time.time) * MarsEclipticOrbitParam.x;
                marsPosition.y = MarsOrbitOffset.y * MarsEclipticOrbitParam.y;
                marsPosition.z = MarsOrbitOffset.z + Mathf.Cos(Time.time) * MarsEclipticOrbitParam.z;
            }
            else if (MarsClockwiseOrbit == false) // Counter-clockwise rotation
            {
                marsPosition.x = MarsOrbitOffset.x + Mathf.Cos(Time.time) * MarsEclipticOrbitParam.x;
                marsPosition.y = MarsOrbitOffset.y * MarsEclipticOrbitParam.y;
                marsPosition.z = MarsOrbitOffset.z + Mathf.Sin(Time.time) * MarsEclipticOrbitParam.z;
            }

            // Mars DrawLine
            Debug.DrawLine(Random.onUnitSphere * MarsSize + marsPosition, Random.onUnitSphere * MarsSize + marsPosition, MarsColor, 0.1f);
        }
    }

    // Phobos
    void displayPhobos()
    {   
        if (Phobos == true)
        {
            if (PhobosClockwiseOrbit == true) // Clockwise rotation
            {
                phobosPosition.x = marsPosition.x + Mathf.Sin(Time.time * PhobosSpeed) * MarsSize * PhobosOrbitDistance;
                phobosPosition.y = marsPosition.y + Mathf.Cos(Time.time * PhobosSpeed) * MarsSize * PhobosOrbitDistance;
                phobosPosition.z = marsPosition.z;
            }
            else if (PhobosClockwiseOrbit == false) // Counter-clockwise rotation
            {
                phobosPosition.x = marsPosition.x + Mathf.Cos(Time.time * PhobosSpeed) * MarsSize * PhobosOrbitDistance;
                phobosPosition.y = marsPosition.y + Mathf.Sin(Time.time * PhobosSpeed) * MarsSize * PhobosOrbitDistance;
                phobosPosition.z = marsPosition.z;
            }
            
            // Phobos DrawLine
            Debug.DrawLine(Random.onUnitSphere * PhobosSize + phobosPosition, Random.onUnitSphere * PhobosSize + phobosPosition, PhobosColor, 0.1f);
        }
    }
}
