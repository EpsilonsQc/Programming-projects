using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DrawAfineCurve : MonoBehaviour
{
    [SerializeField] private float InclinationA = 0f; // Pente
    [SerializeField] private float B = 0f; // Ordonnée à l'origine
    [SerializeField] private float LimitX = 0f;
    [SerializeField] private LineRenderer drawLine;
    
    private Vector2 startPoint = new Vector2(0, 0); // (coordonée x, y)
    private Vector2 endPoint = new Vector2(0, 0); // (coordonée x, y)

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
        // On fait l'appel de la fonction ici pour pouvoir changer certains paramètres (A, B ou X) au runtime
        RenderCurve();
    }
    
    // Dessine la droite à partir de deux points
    void RenderCurve()
    {
        if (drawLine == null) { return; }

        // Calculer des points dans la courbe
        startPoint = CalculatePoint(LimitX);
        endPoint = CalculatePoint(-LimitX);

        drawLine.SetPosition(0, startPoint);
        drawLine.SetPosition(1, endPoint);
    }

    // Calcul la coordonnée Y en fonction d'une coordonnée X donnée, de la pente A et de l'ordonnée à l'origine B
    private Vector2 CalculatePoint(float x)
    {
        Vector2 point = new Vector2();

        point.x = x;
        point.y = x * InclinationA + B;

        return point;
    }
}