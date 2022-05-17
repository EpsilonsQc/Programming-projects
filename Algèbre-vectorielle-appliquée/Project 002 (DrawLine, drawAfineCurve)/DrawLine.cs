using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DrawLine : MonoBehaviour
{
    [SerializeField] private Vector2 startPoint = new Vector2(0, 0); // (coordonée x, y)
    [SerializeField] private Vector2 endPoint = new Vector2(0, 0); // (coordonée x, y)
    [SerializeField] private LineRenderer drawLine;

    // Positions spectrum (for 16:10 aspect radio with camera size 100) : 
    // X min : -160
    // X max : 160
    // Y min : -100
    // Y max : 100

    void Awake()
    {
        drawLine = gameObject.GetComponent<LineRenderer>();
        if (drawLine == null) 
        {
            Debug.Log("<drawLine> : Pas de référence pour le drawLine -> la composante est sûrement manquante!");
        }
    }

    // Start is called before the first frame update
    void Start()
    {
        drawLine.positionCount = 2;
        drawLine.widthMultiplier = 0.25f;   
    }

    // Update is called once per frame
    void Update()
    {
        SetLine(startPoint, endPoint);
    }

    private void SetLine(Vector2 start, Vector2 end)
    {
        if (drawLine == null) 
        { 
            return; 
        }

        drawLine.SetPosition(0, start);
        drawLine.SetPosition(1, end);
    }
}
