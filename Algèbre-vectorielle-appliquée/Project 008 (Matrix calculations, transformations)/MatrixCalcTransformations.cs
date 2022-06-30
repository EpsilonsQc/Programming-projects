using UnityEngine;

public class MatrixCalcTransformations : MonoBehaviour
{
    [HideInInspector] [SerializeField] private GameObject sphere1;
    [HideInInspector] [SerializeField] private GameObject sphere2;
    [HideInInspector] [SerializeField] private GameObject sphere3;
    [HideInInspector] [SerializeField] private GameObject sphere4;
    [HideInInspector] [SerializeField] private GameObject sphere5;
    [HideInInspector] [SerializeField] private GameObject sphere6;
    [HideInInspector] [SerializeField] private GameObject sphere7;
    [HideInInspector] [SerializeField] private GameObject sphere8;

    [SerializeField] private Vector3 position = default;
    [SerializeField] private Vector3 scale = Vector3.one;
    [SerializeField] private Vector3 rotation = default;

    private Vector3 previousPos = default;
    private Vector3 previousScale = default;
    private Vector3 previousRotation = default;
    private GameObject[] sphereCollection;

    private void Awake()
    {
        sphereCollection = GameObject.FindGameObjectsWithTag("Sphere");
        previousPos = position;
        scale = Vector3.one;
        previousScale = scale;
        previousRotation = rotation;
    }

    private void Update()
    {
        Vector3 deltaPos = position - previousPos;
        float magnitudeT = deltaPos.magnitude;

        Vector3 deltaScale = Vector3.one;
        float magnitudeS = deltaScale.magnitude;

        Vector3 deltaRotation = rotation - previousRotation;
        float magnitudeR = deltaRotation.magnitude;

        // Calcul midpoint between sphere 1 and 7 (diagonal)
        Vector3 deltaPosToCenter = new Vector3
        (
            (sphere1.transform.position.x + sphere7.transform.position.x) / 2,
            (sphere1.transform.position.y + sphere7.transform.position.y) / 2,
            (sphere1.transform.position.z + sphere7.transform.position.z) / 2
        );

        string rotateAxis = "0";

        if (previousRotation.x - rotation.x != 0)
        {
            rotateAxis = "x";
        }

        if (previousRotation.y - rotation.y != 0)
        {
            rotateAxis = "y";
        }

        if (previousRotation.z - rotation.z != 0)
        {
            rotateAxis = "z";
        }

        if (previousScale.x != 0 && previousScale.y != 0 && previousScale.z != 0) 
        {
            deltaScale = new Vector3(scale.x / previousScale.x, scale.y / previousScale.y, scale.z / previousScale.z);      
        }
            
        if (magnitudeT > 0f)
        {
            previousPos = position;
            // CalculateTranslation(deltaPos);
        }
        
        if (magnitudeS > 0f)
        {
            previousScale = scale;
            // CalculateScaling(deltaScale, deltaPosToCenter);
        }

        if (magnitudeR > 0f)
        {
            previousRotation = rotation;
            // CalculateRotation(deltaRotation, deltaPosToCenter, rotateAxis);
        }

        CalculateTransform(deltaPos, deltaScale, deltaRotation, deltaPosToCenter, rotateAxis, magnitudeT, magnitudeS, magnitudeR);
    }

    // Calculate translation
    private void CalculateTranslation(Vector3 deltaPos)
    {
        Matrix4x4 matS = GetTranslationMatrix(deltaPos);

        foreach(GameObject GO in sphereCollection)
        {
            Vector4 currPos = new Vector4(GO.transform.position.x, GO.transform.position.y, GO.transform.position.z, 1f);
            Vector4 newPos  = matS * currPos;
            GO.transform.position = (Vector3)newPos;
        }
    }

    // Calculate scaling
    private void CalculateScaling(Vector3 deltaScale, Vector3 deltaPosToCenter)
    {
        Matrix4x4 matT1 = GetTranslationMatrix(-deltaPosToCenter);
        Matrix4x4 matT = GetScalingMatrix(deltaScale);
        Matrix4x4 matT2 = GetTranslationMatrix(deltaPosToCenter);

        Matrix4x4 combo = matT2 * matT * matT1;

        foreach(GameObject GO in sphereCollection)
        {
            Vector4 currPos = new Vector4(GO.transform.position.x, GO.transform.position.y, GO.transform.position.z, 1f);
            Vector4 newPos  = combo * currPos;
            GO.transform.position = (Vector3)newPos;
        }    
    }

    // Calculate rotation
    private void CalculateRotation(Vector3 deltaRotation, Vector3 deltaPosToCenter, string rotateAxis)
    {
        Matrix4x4 matT1 = GetTranslationMatrix(-deltaPosToCenter);
        
        Matrix4x4 matR = default;

        if (rotateAxis == "x")
        {
            matR = GetRotationMatrixX(deltaRotation);
        }

        if (rotateAxis == "y")
        {
            matR = GetRotationMatrixY(deltaRotation);
        }

        if (rotateAxis == "z")
        {
            matR = GetRotationMatrixZ(deltaRotation);
        }

        Matrix4x4 matT2 = GetTranslationMatrix(deltaPosToCenter);

        Matrix4x4 combo = matT2 * matR * matT1;

        foreach(GameObject GO in sphereCollection)
        {
            Vector4 currPos = new Vector4(GO.transform.position.x, GO.transform.position.y, GO.transform.position.z, 1f);
            Vector4 newPos  = combo * currPos;
            GO.transform.position = (Vector3)newPos;
        }
    }

    // Get translation matrix
    private Matrix4x4 GetTranslationMatrix(Vector3 deltaPos)
    {
        Matrix4x4 mat = Matrix4x4.identity;
        mat.m03 = deltaPos.x;
        mat.m13 = deltaPos.y;
        mat.m23 = deltaPos.z;

        return mat;
    }

    // Get scaling matrix
    private Matrix4x4 GetScalingMatrix(Vector3 deltaScale)
    {
        Matrix4x4 mat = Matrix4x4.identity;
        
        mat.SetRow(0, new Vector4(deltaScale.x, 0,               0,             0));
        mat.SetRow(1, new Vector4(0,            deltaScale.y,    0,             0));
        mat.SetRow(2, new Vector4(0,            0,               deltaScale.z,  0));
        mat.SetRow(3, new Vector4(0,            0,               0,             1));

        return mat;
    }

    // Get rotation matrix X
    private Matrix4x4 GetRotationMatrixX(Vector3 deltaRotation)
    {
        Matrix4x4 mat = Matrix4x4.identity;

        mat.m11 = Mathf.Cos(deltaRotation.x);
        mat.m12 = -Mathf.Sin(deltaRotation.x);
        mat.m21 = Mathf.Sin(deltaRotation.x);
        mat.m22 = Mathf.Cos(deltaRotation.x);

        return mat;
    }

    // Get rotation matrix Y
    private Matrix4x4 GetRotationMatrixY(Vector3 deltaRotation)
    {
        Matrix4x4 mat = Matrix4x4.identity;

        mat.m00 = Mathf.Cos(deltaRotation.y);
        mat.m02 = -Mathf.Sin(deltaRotation.y);
        mat.m20 = Mathf.Sin(deltaRotation.y);
        mat.m22 = Mathf.Cos(deltaRotation.y);

        return mat;
    }

    // Get rotation matrix Z
    private Matrix4x4 GetRotationMatrixZ(Vector3 deltaRotation)
    {
        Matrix4x4 mat = Matrix4x4.identity;

        mat.m00 = Mathf.Cos(deltaRotation.z);
        mat.m01 = Mathf.Sin(deltaRotation.z);
        mat.m10 = -Mathf.Sin(deltaRotation.z);
        mat.m11 = Mathf.Cos(deltaRotation.z);

        return mat;
    }

    // Calculate transform
    private void CalculateTransform(Vector3 deltaPosition, Vector3 deltaScale, Vector3 deltaRotation, Vector3 deltaPosToCenter, string rotateAxis, float magnitudeT, float magnitudeS, float magnitudeR)
    {
        if (magnitudeT > 0f)
        {
            CalculateTranslation(deltaPosition);
        }

        if (magnitudeS > 0f)
        {
            CalculateScaling(deltaScale, deltaPosToCenter);
        }

        if (rotateAxis != "0" && magnitudeR > 0f)
        {
            CalculateRotation(deltaRotation, deltaPosToCenter, rotateAxis);
        }
    }
}