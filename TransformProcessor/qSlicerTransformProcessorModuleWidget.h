/*==============================================================================

  Program: 3D Slicer

  Portions (c) Copyright Brigham and Women's Hospital (BWH) All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  This file was originally developed by Franklin King, PerkLab, Queen's University
  and was supported through the Applied Cancer Research Unit program of Cancer Care
  Ontario with funds provided by the Ontario Ministry of Health and Long-Term Care

==============================================================================*/

#ifndef __qSlicerTransformProcessorModuleWidget_h
#define __qSlicerTransformProcessorModuleWidget_h

// SlicerQt includes
#include "qSlicerAbstractModuleWidget.h"

#include "qSlicerTransformProcessorModuleExport.h"

class qSlicerTransformProcessorModuleWidgetPrivate;
class vtkMRMLNode;

/// \ingroup Slicer_QtModules_TransformProcessor
class Q_SLICER_QTMODULES_TRANSFORMPROCESSOR_EXPORT qSlicerTransformProcessorModuleWidget :
  public qSlicerAbstractModuleWidget
{
  Q_OBJECT

public:

  typedef qSlicerAbstractModuleWidget Superclass;
  qSlicerTransformProcessorModuleWidget( QWidget *parent = 0 );
  virtual ~qSlicerTransformProcessorModuleWidget();

  virtual void enter();

public slots:
  void updateGUIFromMRML();

  void setSignalsBlocked( bool );
  bool getSignalsBlocked();

protected slots:
  void onParameterNodeSelected();
  
  void onAddInputCombineTransform();
  void onRemoveInputCombineTransform();
  void onInputFromTransformNodeSelected( vtkMRMLNode* node );
  void onInputToTransformNodeSelected( vtkMRMLNode* node );
  void onInputInitialTransformNodeSelected( vtkMRMLNode* node );
  void onInputChangedTransformNodeSelected( vtkMRMLNode* node );
  void onInputAnchorTransformNodeSelected( vtkMRMLNode* node );
  void onInputForwardTransformNodeSelected( vtkMRMLNode* node );
  void onInputUnstabilizedTransformNodeSelected(vtkMRMLNode* node);
  void onOutputTransformNodeSelected( vtkMRMLNode* node );

  void onProcessingModeChanged( int );
  void onRotationModeChanged( int );
  void onPrimaryAxisChanged( int );
  void onDependentAxesModeChanged( int );
  void onSecondaryAxisChanged( int );
  void onCopyTranslationChanged();

  void onUpdateButtonPressed();
  void onUpdateButtonCheckboxToggled( bool );
  void singleUpdate();
  void handleEventAutoUpdate();

  void onStabilizationFilterCheckBoxToggled(bool);
  void onStabilizationCutOffFrequencyChanged(double);

protected:
  QScopedPointer< qSlicerTransformProcessorModuleWidgetPrivate > d_ptr;
  
  virtual bool eventFilter(QObject * obj, QEvent *event);
  virtual void setup();

  QTimer* updateTimer;

private:
  Q_DECLARE_PRIVATE( qSlicerTransformProcessorModuleWidget );
  Q_DISABLE_COPY( qSlicerTransformProcessorModuleWidget );

  enum TransformRole
  {
    TRANSFORM_ROLE_INPUT_COMBINE = 0,
    TRANSFORM_ROLE_INPUT_FROM,
    TRANSFORM_ROLE_INPUT_TO,
    TRANSFORM_ROLE_INPUT_INITIAL,
    TRANSFORM_ROLE_INPUT_CHANGED,
    TRANSFORM_ROLE_INPUT_ANCHOR,
    TRANSFORM_ROLE_INPUT_FORWARD,
    TRANSFORM_ROLE_INPUT_UNSTABILIZED,
    TRANSFORM_ROLE_OUTPUT,
    TRANSFORM_ROLE_LAST
  };
  // helper function to avoid repeated code ( parameter node checks, downcast checks, etc )
  void SetTransformAccordingToRole( vtkMRMLNode* node, TransformRole role );
};

#endif
