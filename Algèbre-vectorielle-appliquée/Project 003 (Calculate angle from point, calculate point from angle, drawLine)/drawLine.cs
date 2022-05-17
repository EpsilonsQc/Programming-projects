using UnityEngine;

public class drawLine : MonoBehaviour
{   
    [SerializeField] Vector2 startPoint;
    [SerializeField] Vector2 endPoint;

    private LineRenderer lineRenderer;

    void Start()
    {
        lineRenderer = GetComponent<LineRenderer>();

        if (lineRenderer == null) 
        {
            Debug.LogWarning("<DrawLine> : Pas de reference pour le lineRenderer-> la composante est surement manquante!");
        }
    }

    void Update()
    {
        SetLine(startPoint, endPoint);
    }
    
    private void SetLine(Vector2 start, Vector2 end)
    {
        if (lineRenderer == null) { return; }

        lineRenderer.widthMultiplier = 0.25f;
        lineRenderer.positionCount = 2;

        lineRenderer.SetPosition(0, start);
        lineRenderer.SetPosition(1, end);
    }
}
